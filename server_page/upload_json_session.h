#pragma once

#include "asio.hpp"
#include <iostream>
#include "upload_json.h"
class server_page;
class upload_json_session:public std::enable_shared_from_this<upload_json_session>
{
public:
	upload_json_session(asio::io_context& io_context, const asio::ip::tcp::endpoint& endpoint,server_page* sep_);
		
	void start();
	
	void do_accept();
	
	void run();

private:
	asio::ip::tcp::acceptor acceptor_;
	std::vector<std::shared_ptr<upload_json>> sessions;
	asio::io_context& io_context_;
	server_page* ser_ptr_;
};
