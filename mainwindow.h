#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "control.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

private slots:
        void on_submit_button_clicked();

private:
        Ui::MainWindow *ui;
        Control* c;
        Profile* map[MAX_PROFILES];
};
#endif // MAINWINDOW_H
