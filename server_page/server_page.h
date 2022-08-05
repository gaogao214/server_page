#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_server_page.h"
#include "upload_json_session.h"


class server_page : public QMainWindow
{
    Q_OBJECT

public:
    server_page(QWidget *parent = nullptr);
    ~server_page();
    
    Ui::server_pageClass ui;

public slots:
   
    void start_connect(); /*��ʼ����*/
   
    void create_reset_upload();


private:
    //Ui::server_pageClass ui;
    std::shared_ptr<upload_json_session> uj_;

    std::shared_ptr<std::thread> main_thread_ptr_;

    asio::io_context io_context;
};



