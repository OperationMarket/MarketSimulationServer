#include "responce.h"
#include <iostream>
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
		enum { max_length = 1024 };
		char data_[max_length];
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
