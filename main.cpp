#include "mainwindow.h"

#define ORGANIZATION_NAME "Micronix"
#define ORGANIZATION_DOMAIN "www.mx-omsk.ru"
#define APPLICATION_NAME "VD17_Service"

int main(int argc, char* argv[])
{
  QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(APPLICATION_NAME);

  QTextCodec* tc = QTextCodec::codecForName("UTF-8");
  QTextCodec::setCodecForLocale(tc);

  QApplication a(argc, argv);

  MainWindow w;
  w.setWindowFlags(Qt::Window);
  w.show();

  return a.exec();
}
