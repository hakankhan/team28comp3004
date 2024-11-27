#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main_stack->setCurrentIndex(CREATE_PROFILE_PAGE_ID);
    ui->results_tabs->setCurrentIndex(0);
    c = new Control();
    for(int i = 0; i < MAX_PROFILES; i++){
        index_to_profile[i] = NULL;
    }
    current_index_dropdown = -1;
    connect(ui->submit_button, SIGNAL(clicked()), this, SLOT(submit_button_clicked()));
    connect(ui->switch_profile_box, SIGNAL(activated(int)), this, SLOT(profile_changed()));
    connect(ui->new_profile_button, SIGNAL(clicked()), this, SLOT(new_profile_button_clicked()));
    connect(ui->delete_profile_button, SIGNAL(clicked()), this, SLOT(delete_profile()));
    connect(ui->edit_profile_button, SIGNAL(clicked()), this, SLOT(edit_profile_button_clicked()));
    connect(ui->edit_submit_button, SIGNAL(clicked()), this, SLOT(edit_profile_submission()));
    connect(ui->new_scan_button, SIGNAL(clicked()), this, SLOT(scan_button_clicked()));
    connect(ui->submit_scan_button, SIGNAL(clicked()), this, SLOT(submit_scan_button_clicked()));
    connect(ui->scan_results_list,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(display_scan_results(QListWidgetItem*)));
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_profile_dropdown(){
    int num_list_elements = -1;
    ui->switch_profile_box->clear();
    for(int i = 0; i < MAX_PROFILES; i++){
        Profile* p = c->get_profiles()[i];
        num_list_elements++;
        if(p != NULL){
            index_to_profile[num_list_elements] = p;
            ui->switch_profile_box->addItem("Profile " + QString::number(num_list_elements) + ": " + p->get_first_name());
            continue;
        }

        index_to_profile[num_list_elements] = NULL;
    }

    ui->switch_profile_box->setCurrentIndex(current_index_dropdown);
}

void MainWindow::edit_profile_button_clicked(){
    current_index_dropdown = ui->switch_profile_box->currentIndex();

    ui->main_stack->setCurrentIndex(EDIT_PROFILE_PAGE_ID);

    Profile* p = c->get_current_profile();;

    ui->edit_first_name->setText(*p->get_first_name());
    ui->edit_last_name->setText(*p->get_last_name());
    ui->edit_height->setValue(p->get_height());
    ui->edit_weight->setValue(p->get_weight());
    ui->edit_birthday->setDate(*p->get_birthday());
}

void MainWindow::edit_profile_submission(){
    Profile* p = c->get_current_profile();

    p->set_first_name(ui->edit_first_name->text());
    p->set_last_name(ui->edit_last_name->text());
    p->set_height(ui->edit_height->value());
    p->set_weight(ui->edit_weight->value());
    p->set_birthday(ui->edit_birthday->date());

    ui->main_stack->setCurrentIndex(MAIN_PAGE_ID);

    make_profile_dropdown();
}

void MainWindow::new_profile_button_clicked(){
    Profile** arr = c->get_profiles();
    for(int i = 0; i < MAX_PROFILES; i++){
        if(arr[i] == NULL){
            current_index_dropdown = i;
            break;
        }
    }
    ui->main_stack->setCurrentIndex(CREATE_PROFILE_PAGE_ID);

    ui->first_name->clear();
    ui->last_name->clear();
    ui->height->clear();
    ui->weight->clear();
    ui->birthday->clear();
}

void MainWindow::profile_changed(){
    qInfo("changed");
    qInfo("old profile id: %d", c->get_current_profile()->get_id());
    c->set_current_profile(index_to_profile[ui->switch_profile_box->currentIndex()]->get_id());
    qInfo("current profile id: %d", c->get_current_profile()->get_id());
}

void MainWindow::submit_button_clicked()
{
    // push profile to control
    QString fname = ui->first_name->text();
    QString lname = ui->last_name->text();
    QDate bd = ui->birthday->date();
    int height = ui->height->value();
    int weight = ui->weight->value();

    c->add_profile(fname, lname, bd, height, weight);

    ui->main_stack->setCurrentIndex(MAIN_PAGE_ID);
    if(current_index_dropdown == -1){
        current_index_dropdown = 0;
    }
    make_profile_dropdown();
}

void MainWindow::delete_profile(){
    current_index_dropdown = 0;
    int id_to_delete = c->get_current_profile()->get_id();
    if(!c->more_than_one_profile()){
        ui->main_stack->setCurrentIndex(CREATE_PROFILE_PAGE_ID);
        c->delete_profile(id_to_delete);
        return;
    }
    c->delete_profile(id_to_delete);
    make_profile_dropdown();
}

void MainWindow::scan_button_clicked(){
    QVector<QDoubleSpinBox*> spinboxes = make_spinbox_vector();
    Sensor* s = c->get_processor()->get_sensor();
    for(int i = 0; i < 24; i++){
        s->set_value_at_index(i, rand() % 12 + 1);
        spinboxes[i]->setValue(s->get_value_at_index(i));
    }
    ui->main_stack->setCurrentIndex(SCAN_PAGE_ID);
}

QVector<QDoubleSpinBox*> MainWindow::make_spinbox_vector(){
    QVector<QDoubleSpinBox*> spinboxes;
    spinboxes.push_back(ui->LH1_box);
    spinboxes.push_back(ui->LH2_box);
    spinboxes.push_back(ui->LH3_box);
    spinboxes.push_back(ui->LH4_box);
    spinboxes.push_back(ui->LH5_box);
    spinboxes.push_back(ui->LH6_box);
    spinboxes.push_back(ui->RH1_box);
    spinboxes.push_back(ui->RH2_box);
    spinboxes.push_back(ui->RH3_box);
    spinboxes.push_back(ui->RH4_box);
    spinboxes.push_back(ui->RH5_box);
    spinboxes.push_back(ui->RH6_box);
    spinboxes.push_back(ui->LF1_box);
    spinboxes.push_back(ui->LF2_box);
    spinboxes.push_back(ui->LF3_box);
    spinboxes.push_back(ui->LF4_box);
    spinboxes.push_back(ui->LF5_box);
    spinboxes.push_back(ui->LF6_box);
    spinboxes.push_back(ui->RF1_box);
    spinboxes.push_back(ui->RF2_box);
    spinboxes.push_back(ui->RF3_box);
    spinboxes.push_back(ui->RF4_box);
    spinboxes.push_back(ui->RF5_box);
    spinboxes.push_back(ui->RF6_box);
    return spinboxes;
}

void MainWindow::submit_scan_button_clicked(){
    QVector<QDoubleSpinBox*> spinboxes = make_spinbox_vector();
    Sensor* s = c->get_processor()->get_sensor();
    for(int i = 0; i < 24; i++){
        s->set_value_at_index(i, spinboxes[i]->value());
    }

    ui->main_stack->setCurrentIndex(MAIN_PAGE_ID);
    qInfo("test 1");
    ScanResult* result = c->get_processor()->perform_scan();
    qInfo("test 2");
    c->get_current_profile()->add_result(result);
    qInfo("test 3");
    qInfo("made scan %d", c->get_current_profile()->get_history()->get_num_past_results());
    ui->scan_results_list->addItem("Record #" + QString::number(c->get_current_profile()->get_history()->get_num_past_results()));
}

void MainWindow::display_scan_results(QListWidgetItem *item){
    //TODO: push results to display in tabs
    int itemID = item->text().split("#")[1].toInt() - 1;
    qInfo() << "opening record" << itemID;
    ui->main_stack->setCurrentIndex(RESULTS_PAGE_ID);

//    ui->results_table
}
