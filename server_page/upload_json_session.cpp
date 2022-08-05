#include "upload_json_session.h"
#include <iostream>
#include "upload_json.h"
#include "server_page.h"
	upload_json_session::upload_json_session(asio::io_context& io_context, const asio::ip::tcp::endpoint& endpoint,server_page* sep_)
		:io_context_(io_context)
		,acceptor_(io_context, endpoint)
		,ser_ptr_(sep_)
		//,ser_ptr_(new server_page())
	{
		start();
	}

	void upload_json_session::start()
	{
		do_accept();
	}

	void upload_json_session::do_accept()
	{
		ser_ptr_->ui.text_log->insertPlainText(u8"�����������ɹ�\n");

		acceptor_.async_accept(
			[this](std::error_code ec, asio::ip::tcp::socket socket)
			{
				if (!ec)
				{
					//ser_ptr_->ui.connect->setText(u8"���ӳɹ�");
					ser_ptr_->ui.text_log->insertPlainText(u8"s�˿�12312 ���ӳɹ�\n");

					/*std::cout << "����˶˿� 12312 �Ϳͻ��˶˿� 12312 ���ӳɹ�\n";*/
					auto s = std::make_shared<upload_json>(std::move(socket));
					s->start();
					sessions.push_back(s);
				}
				else {
					std::cout << "����˶˿� 12312 �Ϳͻ��˶˿� 12312 ����ʧ��\n";
				}
				//do_accept();
			});
	}

	void upload_json_session::run()
	{
		io_context_.run();
	}
