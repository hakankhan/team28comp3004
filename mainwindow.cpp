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
<<<<<<< HEAD
    connect(ui->submit_button, SIGNAL(clicked()), this, SLOT(on_submit_button_clicked()));
=======
    for(int i = 0; i < MAX_PROFILES; i++){
        index_to_profile[i] = NULL;
    }
    connect(ui->submit_button, SIGNAL(clicked()), this, SLOT(submit_button_clicked()));
    connect(ui->switch_profile_box, SIGNAL(activated(int)), this, SLOT(profile_changed()));
    connect(ui->new_profile_button, SIGNAL(clicked()), this, SLOT(new_profile_button_clicked()));
>>>>>>> 9803a8765763de9e3eb587bf485d985f56f57bc7
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
void MainWindow::on_submit_button_clicked()
=======
void MainWindow::profile_changed(){
    qInfo("changed");
    qInfo("old profile id: %d", c->get_current_profile()->get_id());
    c->set_current_profile(index_to_profile[ui->switch_profile_box->currentIndex()]->get_id());
    qInfo("current profile id: %d", c->get_current_profile()->get_id());
}

void MainWindow::submit_button_clicked()
>>>>>>> 9803a8765763de9e3eb587bf485d985f56f57bc7
{
    // push profile to control
    QString fname = ui->first_name->text();
    QString lname = ui->last_name->text();
    QDate bd = ui->birthday->date();
    int height = ui->height->value();
    int weight = ui->weight->value();

    c->add_profile(fname, lname, bd, height, weight);

    ui->main_stack->setCurrentIndex(1);



    int num_list_elements = -1;
    for(int i = 0; i < MAX_PROFILES; i++){
        Profile* p = c->get_profiles()[i];
<<<<<<< HEAD
        qInfo("Profiles array element:");
        qInfo("i = %d", i);
        if(p != NULL){
            qInfo("Not null!");
            index_to_profile[num_list_elements++] = p;
            ui->switch_profile_box->addItem("Profile " + QString(num_list_elements) + ": " + p->get_first_name());
=======
        num_list_elements++;
        if(p != NULL){
            index_to_profile[num_list_elements] = p;
            ui->switch_profile_box->addItem("Profile " + QString::number(num_list_elements) + ": " + p->get_first_name());
>>>>>>> 9803a8765763de9e3eb587bf485d985f56f57bc7
            continue;
        }

        index_to_profile[num_list_elements] = NULL;
    }
}

