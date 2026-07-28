#include "mainwindow.h"

#define ORGANIZATION_NAME "Micronix"
#define ORGANIZATION_DOMAIN "www.mx-omsk.ru"
#define APPLICATION_NAME "VD17_Service"

#include <QApplication>
#include <mainwindow.h>

static void applyAppStyle(QApplication &app)
{
    QFile file(":/support/app.qss");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        app.setStyleSheet(QString::fromUtf8(file.readAll()));
        file.close();
    }
}

int main(int argc, char* argv[])
{
  QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
  QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
  QCoreApplication::setApplicationName(APPLICATION_NAME);

  QTextCodec* tc = QTextCodec::codecForName("UTF-8");
  QTextCodec::setCodecForLocale(tc);

  QApplication a(argc, argv);

  a.setWindowIcon(QIcon(":/support/MX_png_icon.png")); // Глобальная иконка для всех окон приложения
  // applyAppStyle(a); // Глобальный стиль для всех окон и диалогов

  a.setApplicationName(APPLICATION_NAME);
  a.setOrganizationName(ORGANIZATION_NAME);
  a.setOrganizationDomain(ORGANIZATION_DOMAIN);

  MainWindow w;
  w.setWindowFlags(Qt::Window);
  w.show();

  return a.exec();
}
