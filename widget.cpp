#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QHostInfo>
Widget::Widget(secondWindow *secondWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_secondWindow(secondWindow) // Сохраняем указатель на SecondWindow

{
    ui->setupUi(this);



}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButtonResolve_clicked()
{

    //получаем доменное имя из текстового поля
    QString hostName = ui->lineEditHostName->text();

    if (hostName.isEmpty()) {
         QMessageBox::warning(this, "Ошибка", "Введите имя хоста!");
         return;
      }

      QHostInfo hostInfo = QHostInfo::fromName(hostName);

      if (hostInfo.error() != QHostInfo::NoError) {
          m_secondWindow->getLabelResult()->setText("Ошибка: не удалось разрешить имя хоста.");
          return;
      }

      QStringList ipAddresses;

      for (const QHostAddress &address : hostInfo.addresses()) {
          ipAddresses << address.toString();
      }

      if (ipAddresses.isEmpty()) {
          m_secondWindow->getLabelResult()->setText("IP-адрес не найден.");
      } else {
          m_secondWindow->getLabelResult()->setText("IP-адрес(а): " + ipAddresses.join(", "));
      }
      // Убедитесь, что второе окно отображается
          if (!m_secondWindow->isVisible()) {
              m_secondWindow->show();
          }
}

