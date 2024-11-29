#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "control.h"
#include <QDoubleSpinBox>
#include <cstdlib>
#include <ctime>
#include <QListWidget>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

enum pages {
    CREATE_PROFILE_PAGE_ID = 0,
    MAIN_PAGE_ID = 1,
    EDIT_PROFILE_PAGE_ID = 2,
    RESULTS_PAGE_ID = 3,
    SCAN_PAGE_ID = 4
};

using namespace std;

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
        void scan_button_clicked();
        void delete_profile();
        void submit_scan_button_clicked();
        void display_scan_results(QListWidgetItem *item);
        void return_to_main_clicked();
    private:
        Ui::MainWindow *ui;
        Control* c;
        Profile* index_to_profile[MAX_PROFILES];
        void make_profile_dropdown();
        void make_records_list();
        QVector<QDoubleSpinBox*> make_spinbox_vector();
        int current_index_dropdown;
        QString statusToQString(status);
        QGraphicsScene scene;
};
#endif // MAINWINDOW_H
