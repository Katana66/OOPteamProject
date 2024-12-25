#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostInfo>
#include "secondwindow.h" //  заголовок второго окна
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }




QT_END_NAMESPACE

class Widget : public QWidget

{
  Q_OBJECT

public:
    explicit Widget(secondWindow *secondWindow, QWidget *parent = nullptr);;
    ~Widget();



private slots:


    void on_pushButtonResolve_clicked();

private:
    Ui::Widget *ui;
    secondWindow *m_secondWindow; // Указатель на SecondWindow
};
#endif // WIDGET_H
