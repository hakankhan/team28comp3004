#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main_stack->setCurrentIndex(0);
    ui->results_tabs->setCurrentIndex(0);
    c = new Control();
    connect(ui->submit_button, SIGNAL(clicked()), this, SLOT(on_submit_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_button_clicked()
{
    // push profile to control
    QString fname = ui->first_name->text();
    QString lname = ui->last_name->text();
    QDate bd = ui->birthday->date();
    int height = ui->height->value();
    int weight = ui->weight->value();

    c->add_profile(fname, lname, bd, height, weight);

    ui->main_stack->setCurrentIndex(1);



    int num_list_elements = 0;
    for(int i = 0; i < MAX_PROFILES; i++){
        Profile* p = c->get_profiles()[i];
        qInfo("Profiles array element:");
        qInfo("i = %d", i);
        if(p != NULL){
            qInfo("Not null!");
            index_to_profile[num_list_elements++] = p;
            ui->switch_profile_box->addItem("Profile " + QString(num_list_elements) + ": " + p->get_first_name());
            continue;
        }
    }
}

