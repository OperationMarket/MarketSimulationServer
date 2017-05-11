#include <boost/asio.hpp>

#include "netConnect.h"

int main()
{

	boost::asio::io_service io_service;

	server s(io_service, 38768);

	io_service.run();

	return 0;
}
