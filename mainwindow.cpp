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
    connect(ui->return_button,SIGNAL(clicked()),this,SLOT(return_to_main_clicked()));
    srand(time(0));
    good_images_hash.insert("lungs",QPixmap(":/images/good_diagram_status/lungs.PNG"));
    good_images_hash.insert("adrenal_glands",QPixmap(":/images/good_diagram_status/adrenal_glands.PNG"));
    good_images_hash.insert("bladder",QPixmap(":/images/good_diagram_status/bladder.PNG"));
    good_images_hash.insert("body",QPixmap(":/images/good_diagram_status/body.PNG"));
    good_images_hash.insert("gall_bladder",QPixmap(":/images/good_diagram_status/gall_bladder.PNG"));
    good_images_hash.insert("heart",QPixmap(":/images/good_diagram_status/heart.PNG"));
    good_images_hash.insert("kidneys",QPixmap(":/images/good_diagram_status/kidneys.PNG"));
    good_images_hash.insert("large_intestine",QPixmap(":/images/good_diagram_status/large_intestine.PNG"));
    good_images_hash.insert("liver",QPixmap(":/images/good_diagram_status/liver.PNG"));
    good_images_hash.insert("lymph",QPixmap(":/images/good_diagram_status/lymph.PNG"));
    good_images_hash.insert("pancreas",QPixmap(":/images/good_diagram_status/pancreas.PNG"));
    good_images_hash.insert("pericardum",QPixmap(":/images/good_diagram_status/pericardum.PNG"));
    good_images_hash.insert("small_intestine",QPixmap(":/images/good_diagram_status/small_intestine.PNG"));
    good_images_hash.insert("spleen",QPixmap(":/images/good_diagram_status/spleen.PNG"));
    good_images_hash.insert("stomach",QPixmap(":/images/good_diagram_status/stomach.PNG"));

    scene.addPixmap(good_images_hash.value("lungs"));
    scene.addPixmap(good_images_hash.value("adrenal_glands"));
}
void MainWindow::make_image_hash(){
    QStringList organs = {"adrenal_glands","bladder","body","gall_bladder","heart","kidneys",\
                          "large_intestine","liver","lungs","lymph","pancreas","pericardium",\
                          "small_intestine","spleen","stomach"};
    for(int i = 0; i < organs.size(); i++){
        good_images_hash.insert(organs[i],QPixmap(":/images/good_diagram_status/" + organs[i] + ".PNG"));
    }
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
        if(p != NULL){
            num_list_elements++;
            index_to_profile[num_list_elements] = p;
            ui->switch_profile_box->addItem("Profile " + QString::number(num_list_elements) + ": " + p->get_first_name());
            continue;
        }

//        index_to_profile[num_list_elements] = NULL;
    }
    ui->switch_profile_box->setCurrentIndex(current_index_dropdown);
}



void MainWindow::make_records_list(){
    ui->scan_results_list->clear();
    Profile *p = c->get_current_profile();
    if(p->get_history() == NULL){
        return;
    }
    for(int i = 0; i < p->get_history()->get_num_past_results(); i++){
        ui->scan_results_list->addItem("Record #" + QString::number(i));
    }
}

void MainWindow::edit_profile_button_clicked(){
    current_index_dropdown = ui->switch_profile_box->currentIndex();

    ui->main_stack->setCurrentIndex(EDIT_PROFILE_PAGE_ID);

    Profile* p = c->get_current_profile();

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
    make_records_list();
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
    make_records_list();
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
    make_records_list();
}

void MainWindow::delete_profile(){
    current_index_dropdown = 0;
    int id_to_delete = c->get_current_profile()->get_id();
    int dropdown_index = ui->switch_profile_box->currentIndex();
    if(!c->more_than_one_profile()){
        ui->main_stack->setCurrentIndex(CREATE_PROFILE_PAGE_ID);
        c->delete_profile(id_to_delete);
        return;
    }
    c->delete_profile(id_to_delete);
    for(int i = dropdown_index; i < MAX_PROFILES - 1; i++){
            index_to_profile[i] = index_to_profile[i+1];
        }
    index_to_profile[MAX_PROFILES - 1] = NULL;
    make_profile_dropdown();
    make_records_list();
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
    make_records_list();
}

void MainWindow::display_scan_results(QListWidgetItem *item){
    //TODO: push results to display in tabs
    int itemID = item->text().split("#")[1].toInt();
    QTableWidget* tb = ui->results_table;
    QGraphicsView* disp = ui->diagram_graphics;
    qInfo() << "opening record" << itemID;
    ui->main_stack->setCurrentIndex(RESULTS_PAGE_ID);
    ScanResult* r = c->get_current_profile()->get_result(itemID);
    tb->setItem(0,0,new QTableWidgetItem(statusToQString(r->get_lungs_status())));
    tb->setItem(1,0,new QTableWidgetItem(statusToQString(r->get_heart_status())));
    tb->setItem(2,0,new QTableWidgetItem(statusToQString(r->get_pericardium_status())));
    tb->setItem(3,0,new QTableWidgetItem(statusToQString(r->get_liver_status())));
    tb->setItem(4,0,new QTableWidgetItem(statusToQString(r->get_gall_bladder_status())));
    tb->setItem(5,0,new QTableWidgetItem(statusToQString(r->get_stomach_status())));
    tb->setItem(6,0,new QTableWidgetItem(statusToQString(r->get_spleen_status())));
    tb->setItem(7,0,new QTableWidgetItem(statusToQString(r->get_pancreas_status())));
    tb->setItem(8,0,new QTableWidgetItem(statusToQString(r->get_kidney_status())));
    tb->setItem(9,0,new QTableWidgetItem(statusToQString(r->get_adrenal_glands_status())));
    tb->setItem(10,0,new QTableWidgetItem(statusToQString(r->get_small_intestine_status())));
    tb->setItem(11,0,new QTableWidgetItem(statusToQString(r->get_large_intestine_status())));
    tb->setItem(12,0,new QTableWidgetItem(statusToQString(r->get_bladder_status())));
    tb->setItem(13,0,new QTableWidgetItem(statusToQString(r->get_lymph_status())));
    disp->setScene(&scene);
    disp->show();
//    ui->results_table
}

void MainWindow::return_to_main_clicked(){
    ui->main_stack->setCurrentIndex(MAIN_PAGE_ID);
}

QString MainWindow::statusToQString(status s){
    switch(s){
        case NEUTRAL:
            return QString("Average");
        case BAD:
            return QString("Poor");
        case GOOD:
            return QString("Excellent");
        default:
            return QString("");
    }
}
