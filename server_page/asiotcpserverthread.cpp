#include "asiotcpserverthread.h"
/*asiotcpserverthread*/
asiotcpserverthread::asiotcpserverthread()
{

}

asiotcpserverthread::~asiotcpserverthread()
{

}

void asiotcpserverthread::run()
{
	const int port = 10800;
	try 
	{
		asio::io_context io_context;
		server_accept s(io_context,port);
		io_context.run();
	
	}
	catch (std::exception& e)
	{

	}
}
/*server_accept类*/
server_accept::server_accept(asio::io_service& io_context, short port)
	: io_context(io_context), acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
	start_accept();
}

void server_accept::start_accept()
{
	session* new_session = new session(io_context);
	/*acceptor_.async_accept(new_session->socket(),
		boost::bind(&server::handle_accept, this, new_session,
			boost::asio::placeholders::error));*/

	acceptor_.async_accept(
		[this](std::error_code ec, asio::ip::tcp::socket socket)
		{
			if (!ec)
			{

			}
			else 
			{


			}
		});
}

void server_accept::handle_accept(session* new_session, const std::error_code ec)
{
	if (!ec)
	{
		new_session->start();
	}
	else
	{
		delete new_session;
	}
	start_accept();
}
/*session*/
session::session(asio::io_context& io_context) :socket_(io_context)
{


}

asio::ip::tcp::socket& session::socket()
{
	return socket_;
}
void session::start()
{
//	socket_.async_read_some(asio::buffer(data_, max_length)), asio::bind(&session::handle_read, this,
//		asio::placeholders::error,
//	asio::placeholders::bytes_transferred));//异步读取完毕后调用handle_read函数7

}

void session::handle_read(const std::error_code ec, size_t bytes_transferred)
{
	if (!ec)
	{
		//boost::asio::async_write(socket_,
		//	boost::asio::buffer(data_, bytes_transferred),
		//	boost::bind(&session::handle_write, this, boost::asio::placeholders::error));//写完毕后调用handle_write函数
	}
	else
	{
		delete this;
	}
}

