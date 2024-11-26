#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "control.h"
#include <QStyledItemDelegate>

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
        void submit_button_clicked();
        void profile_changed();
        void new_profile_button_clicked();
        void edit_profile_button_clicked();
        void edit_profile_submission();
        void delete_profile();

    private:
        Ui::MainWindow *ui;
        Control* c;
        Profile* index_to_profile[MAX_PROFILES];
        void make_profile_dropdown();
        int current_index_dropdown;
};
#endif // MAINWINDOW_H
