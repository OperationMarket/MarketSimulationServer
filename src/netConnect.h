#include "responce.h"
#include <time.h>
#ifndef NETCONNECT_H
#define NETCONNECT_H

class session : public std::enable_shared_from_this<session> {
	public:
		session(tcp::socket socket) : socket_(std::move(socket)) {

		}

		void start() {
			time_t rawtime;
			time(&rawtime);
			
			data_[max_length]='\0';
			data_[0]='\0';

			std::cout << "Connection From: " << socket_.remote_endpoint().address().to_string() << " on: " << ctime (&rawtime);
			do_read();
		}

	private:
		void do_read() {
			auto self(shared_from_this());
			socket_.async_read_some(boost::asio::buffer(data_, max_length-1), [this, self](boost::system::error_code ec, std::size_t length){
				
				data_[length]='\0';
				
				if (!ec && length < max_length-1) {
					std::string message = test(data_);
					do_write(message.size(), message);
				}
				else{

					socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
                                        socket_.close();
				}
			});
		}

		void do_write(std::size_t length, std::string message)
		{
			if(length < max_length-1){
				auto self(shared_from_this());
				boost::asio::async_write(socket_, boost::asio::buffer(message, length), [this, self](boost::system::error_code ec, std::size_t /*length*/) {
					
					socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
					socket_.close();
				});
			}
			else{

				socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
				socket_.close();
			}
		}

		tcp::socket socket_;
		enum { max_length = 1024 };
		char data_[max_length];
};

class server{
	public:
		server(boost::asio::io_service& io_service, short port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)), socket_(io_service){

			do_accept();
		}

	private:
		void do_accept() {
			acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
				if (!ec) {

					std::make_shared<session>(std::move(socket_))->start();
				}

				do_accept();
			});
		}

		tcp::acceptor acceptor_;
		tcp::socket socket_;
};

#endif
