#include "asio_server_run.h"

asio_server_run::asio_server_run()
{

}
asio_server_run::~asio_server_run()
{}

void asio_server_run::run()
{
	try
	{
		asio::io_context io_context;
		server_accept s(io_context, port);
		io_context.run();

	}
	catch (std::exception& e)
	{

	}

}

server_accept::server_accept(asio::io_service& io_context, short port)
	: io_context(io_context), acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
	start_accept();
}

void server_accept::start_accept()
{
	acceptor_.async_accept(
		[this](std::error_code ec, asio::ip::tcp::socket socket)
		{
			if (!ec)
			{
			//	handle_accept(new_session, ec);
			}
			else
			{

				
			}
		});
}
//
//void server_accept::handle_accept(session* new_session, const std::error_code ec)
//{
//	if (!ec)
//	{
//		new_session->start();
//	}
//	else
//	{
//		delete new_session;
//	}
//	start_accept();
//}