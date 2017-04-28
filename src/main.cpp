#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <microhttpd.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#define PORT 80

boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;

static int answer_to_connection (void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, size_t *upload_data_size, void **con_cls) {

        const char *page = "Hello, World!";
        struct MHD_Response *response;
        int ret;

        response = MHD_create_response_from_buffer (strlen (page), (void *) page, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response (connection, MHD_HTTP_OK, response);

        time_t rawtime;
        time(&rawtime);
        std::cout << "Connection on (UTC) " << ctime (&rawtime);

        MHD_destroy_response (response);

        return ret;
}


int main () {
        struct MHD_Daemon *daemon;

        boost::log::add_file_log(
                boost::log::keywords::file_name = "test_%N",
                boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
                boost::log::keywords::format = "[%TimeStamp%]: %Message%"
        );
        boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
        boost::log::add_common_attributes();

        BOOST_LOG_SEV(lg, boost::log::trivial::info) << "Starting webserver daemon.";
        daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);

        if (NULL == daemon){
                return 1;
        }

        (void) getchar ();

        MHD_stop_daemon (daemon);
        return 0;
}
