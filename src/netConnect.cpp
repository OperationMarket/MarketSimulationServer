#include "netConnect.h"

void session::start() {
	time_t rawtime;
	time(&rawtime);
	
	try{

		std::cout << "Connection From: " << socket_.remote_endpoint().address().to_string() << " on: " << ctime (&rawtime);
	}
	catch (std::exception& e){

		std::cerr << "Exception: " << e.what() << "\n";
	}
	do_read();
}

void session::do_read() {
	
	boost::asio::async_read_until(socket_, b, '\n', boost::bind(&session::handler, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void session::handler(const boost::system::error_code& error, std::size_t bytes_transferred){
	
	if (!error && bytes_transferred < max_length) {
		
		std::istream is(&b);
		std::string line;
		std::getline(is, line);

		std::string message = test(line);
		//std::cout << message;
		do_write(message.size(), message);
	}
	else{
		try{

			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
			socket_.close();
		}
		catch (std::exception& e){

			std::cerr << "Exception: " << e.what() << "\n";
		}
	}

}

void session::do_write(std::size_t length, std::string message)
{
	if(length < max_length){
		auto self(shared_from_this());
		boost::asio::async_write(socket_, boost::asio::buffer(message, length), [this, self](boost::system::error_code ec, std::size_t /*length*/) {
			try{

				socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
                        	socket_.close();
			}
			catch (std::exception& e){

				std::cerr << "Exception: " << e.what() << "\n";
			}
		});
	}
	else{
		try{
		
        		socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
       			socket_.close();
		}
		catch (std::exception& e){

       			 std::cerr << "Exception: " << e.what() << "\n";
		}
	}
}

session::session(tcp::socket socket) : socket_(std::move(socket)) {

}

void server::do_accept() {
	acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
		if (!ec) {

			std::make_shared<session>(std::move(socket_))->start();
		}

		do_accept();
	});
}

server::server(boost::asio::io_service& io_service, short port) : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)), socket_(io_service){

	do_accept();
}
