#include "responce.h"
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

#ifndef NETCONNECT_H
#define NETCONNECT_H

class session : public std::enable_shared_from_this<session> {
	public:

		session(tcp::socket);
		void start();
	private:

		void do_read();
		void do_write(std::size_t, std::string);
		tcp::socket socket_;
		int max_length = 1024;
		boost::asio::streambuf b;
		void handler(const boost::system::error_code&, std::size_t);
};

class server{
	public:

		server(boost::asio::io_service&, short);
	private:

		void do_accept();

		tcp::acceptor acceptor_;
		tcp::socket socket_;
};

#endif
