#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::tcp;

#include "netConnect.h"

int main()
{

	boost::asio::io_service io_service;

	server s(io_service, 38768);

	io_service.run();

	return 0;
}
