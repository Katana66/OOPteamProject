#include "secondwindow.h"
#include "ui_secondwindow.h"
#include<QClipboard>
#include<QMessageBox>
secondWindow::secondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

QLabel* secondWindow::getLabelResult() const {
    return ui->labelResult; //   labelResult определен в вашем UI
}

void secondWindow::on_pushButton_clicked()
{
     QString ipAddress = ui->labelResult->text();

    if (!ipAddress.isEmpty()) {
           QClipboard *clipboard = QGuiApplication::clipboard();
           clipboard->setText(ipAddress);
           QMessageBox::information(this, "Копирование", "IP-адрес скопирован в буфер обмена.");
       } else {
           QMessageBox::warning(this, "Ошибка", "Нет IP-адреса для копирования.");
       }
}

