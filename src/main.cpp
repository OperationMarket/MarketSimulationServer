#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <microhttpd.h>
#include <stdio.h>
#include <iostream>
#include "util/logger.h"

#define PORT 80


static int answer_to_connection (void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version, const char *upload_data, size_t *upload_data_size, void **con_cls) {

        const char *page = "Hello, World!";
        struct MHD_Response *response;
        int ret;

        response = MHD_create_response_from_buffer (strlen (page), (void *) page, MHD_RESPMEM_PERSISTENT);
        ret = MHD_queue_response (connection, MHD_HTTP_OK, response);

        time_t rawtime;
        time(&rawtime);

        Logger::log("Connection received.", INFO);

        MHD_destroy_response (response);

        return ret;
}


int main () {
        struct MHD_Daemon *daemon;

        Logger::log("Starting daemon.", INFO);
        daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL, &answer_to_connection, NULL, MHD_OPTION_END);

        if (NULL == daemon){
                return 1;
        }

        (void) getchar ();

        Logger::log("Stopping daemon.", INFO);
        MHD_stop_daemon (daemon);
        return 0;
}
