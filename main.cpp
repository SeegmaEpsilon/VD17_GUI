#include "mainwindow.h"

#define ORGANIZATION_NAME "Micronix"
#define ORGANIZATION_DOMAIN "www.mx-omsk.ru"
#define APPLICATION_NAME "VD17_Service"

int main(int argc, char *argv[])
{
  QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(APPLICATION_NAME);

  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}
