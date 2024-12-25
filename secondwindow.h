#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QLabel>

namespace Ui {
class secondWindow;
}

class secondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondWindow(QWidget *parent = nullptr);
    ~secondWindow();

QLabel* getLabelResult() const;

private slots:
void on_pushButton_clicked();

private:
    Ui::secondWindow *ui;
};

#endif // SECONDWINDOW_H
