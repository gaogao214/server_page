#include "server_page.h"
#include <QtWidgets/QApplication>
#include "asio.hpp"
#include "upload_json.h"
#include "server_page.h"
#include <QStyleFactory>
#include <Qimage>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server_page w;
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    w.setWindowTitle(u8"版本管理工具服务端");
   
    w.show();
    
    return a.exec();
}
