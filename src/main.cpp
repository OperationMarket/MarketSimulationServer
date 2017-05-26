#include <boost/asio.hpp>
#include "netConnect.h"

int main()
{
        try{

                boost::asio::io_service io_service;
                server s(io_service, 38768);
                io_service.run();
        }
        catch (std::exception& e){

                std::cerr << "Exception: " << e.what() << "\n";
        }

        return 0;
}
