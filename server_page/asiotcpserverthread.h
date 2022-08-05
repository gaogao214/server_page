#pragma once

#include "asio.hpp"

class asiotcpserverthread
{
public :
	asiotcpserverthread();
	~asiotcpserverthread();
protected:
	void run();
};


class session {

public:
	session(asio::io_context& io_context);
	asio::ip::tcp::socket& socket();

	void start();
private:
	void handle_read(const std::error_code ec , size_t bytes_transferred);
	void handle_write(const std::error_code ec);

	asio::ip::tcp::socket socket_;
	enum { max_length = 1024 };
	char data_[max_length];
};

class server_accept
{

public:
	server_accept(asio::io_context& io_context, short port);

private:
	void start_accept();
	void handle_accept(session* new_seesion, const std::error_code ec);

	asio::io_context& io_context;
	asio::ip::tcp::acceptor acceptor_;


};