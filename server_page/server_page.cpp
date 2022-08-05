#include "asio.hpp"

#include "server_page.h"
#include "upload_json_session.h"
#include "wget_load_file.h"
#include <QPushbutton>
#include <QPainter>
server_page::server_page(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	// connect(ui.connect, SIGNAL(clicked(bool)), this, SLOT(start_connect(bool)));
	// ui.connect->setCheckable(true);
	connect(ui.connect, &QPushButton::clicked, this, &server_page::start_connect);   //等待连接
	connect(ui.reset_upload, &QPushButton::clicked, this, &server_page::create_reset_upload);

}

server_page::~server_page()
{}



void server_page::start_connect()
{
	ui.reset_upload->setEnabled(true);

	//std::thread main_thread([this]() 
	/*main_thread_ptr_.reset(new std::thread([this]()
		{
			*/

			asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), std::atoi("12312"));

			// std::shared_ptr<server> s = std::make_shared<server>(io_context, endpoint);
			//upload_json s(io_context, endpoint);
			uj_=std::make_shared<upload_json_session>(io_context, endpoint,this);

			//io_context.run();
			uj_->run();
		//}));

	//main_thread.detach();
}



void server_page::create_reset_upload()
{
	std::thread t1([]()
		{
			asio::io_context io_context_1;
			asio::ip::tcp::endpoint endpoint_1(asio::ip::tcp::v4(), std::atoi("12313"));

			wget_c_file_accept s(io_context_1, endpoint_1);

			//io_context_1.run();

			s.run();
		});

	t1.detach();

	ui.reset_upload->setText(u8"断点续传已启动");
	ui.reset_upload->setEnabled(false);
}
