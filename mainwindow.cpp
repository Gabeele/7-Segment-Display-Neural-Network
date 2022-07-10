#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mlp = new MultiLayerPerceptron({7, 7, 10}); //Number of inputs, number of hidden nodes, number of outputs
}

MainWindow::~MainWindow()
{
    delete ui;
}

int slope(int position){
    int slope = 1 * (255 - 10) / (100 - 0 );
    int mapped = 10 + slope * (position - 0);
    return mapped;
}

bool verifyNumbers(std::string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


void MainWindow::calculate_NN()
{
    vector<double> result = mlp->run(this->input);

    int index = mlp->convert(result);

    writeToLabel(index, result[index]);
}


void MainWindow::writeToLabel(int perdiction, double percentage)
{
    ui->RawOutputLabel->setText("Certainty: " + QString::number(percentage*100) + "%");
    ui->outputLabel->setText(QString::number(perdiction));
}

void MainWindow::on_learnBtn_clicked()
{
    int amount = ui->epochSpinBox->value();
     this->epochsAmount += amount;
            MSE = mlp->train(amount);
            ui->MSElabel->setText("MSE: " + QString::number(MSE));
            ui->EpochsTrainedLabel->setText("Epochs Trained: " + QString::number(this->epochsAmount));
            calculate_NN();

}


void MainWindow::on_slider_1_sliderReleased()
{
int position = ui->slider_1->value();
    this->input.at(0) = position / 10;
    calculate_NN();
}

void MainWindow::on_slider_2_sliderReleased()
{
int position = ui->slider_2->value();
    this->input.at(1) = position / 10;
    calculate_NN();
}

void MainWindow::on_slider_3_sliderReleased()
{
    int position = ui->slider_3->value();
    this->input.at(2) = position / 10;
    calculate_NN();
}


void MainWindow::on_slider_4_sliderReleased()
{
    int position = ui->slider_4->value();
    this->input.at(3) = position / 10;
    calculate_NN();
}

void MainWindow::on_slider_5_sliderReleased()
{
    int position = ui->slider_5->value();
    this->input.at(4) = position / 10;
    calculate_NN();
}


void MainWindow::on_slider_6_sliderReleased()
{
    int position = ui->slider_6->value();
    this->input.at(5) = position / 10;
    calculate_NN();
}


void MainWindow::on_slider_7_sliderReleased()
{
    int position = ui->slider_7->value();
    this->input.at(6) = position / 10;
    calculate_NN();
}

void MainWindow::reset_UI(){

    ui->slider_1->setSliderPosition(0);
    ui->slider_2->setSliderPosition(0);
    ui->slider_3->setSliderPosition(0);
    ui->slider_4->setSliderPosition(0);
    ui->slider_5->setSliderPosition(0);
    ui->slider_6->setSliderPosition(0);
    ui->slider_7->setSliderPosition(0);

    on_slider_1_sliderMoved(0);
    on_slider_2_sliderMoved(0);
    on_slider_3_sliderMoved(0);
    on_slider_4_sliderMoved(0);
    on_slider_5_sliderMoved(0);
    on_slider_6_sliderMoved(0);
    on_slider_7_sliderMoved(0);

    ui->EpochsTrainedLabel->setText("Epochs Trained: ---");
    ui->MSElabel->setText("MSE: ---");
    ui->RawOutputLabel->setText("Certainty: ---");
    ui->epochSpinBox->setValue(1000);
    ui->outputLabel->setText("---");
}


void MainWindow::on_resetBtn_clicked()
{
    reset_UI();
    mlp = new MultiLayerPerceptron({7, 7, 10});
    MSE = 0.0;
    epochsAmount = 0;

}

void MainWindow::on_slider_1_sliderMoved(int position)
{

   ui->slider_1->setStyleSheet("QSlider::groove:horizontal"
                               "{"
                               "height: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:horizontal "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}
void MainWindow::on_slider_4_sliderMoved(int position)
{

   ui->slider_4->setStyleSheet("QSlider::groove:horizontal"
                               "{"
                               "height: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:horizontal "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}
void MainWindow::on_slider_7_sliderMoved(int position)
{

   ui->slider_7->setStyleSheet("QSlider::groove:horizontal"
                               "{"
                               "height: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:horizontal "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}


void MainWindow::on_slider_2_sliderMoved(int position)
{

   ui->slider_2->setStyleSheet("QSlider::groove:vertical"
                               "{"
                               "width: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:vertical "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}

void MainWindow::on_slider_5_sliderMoved(int position)
{

   ui->slider_5->setStyleSheet("QSlider::groove:vertical"
                               "{"
                               "width: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:vertical "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}

void MainWindow::on_slider_6_sliderMoved(int position)
{

   ui->slider_6->setStyleSheet("QSlider::groove:vertical"
                               "{"
                               "width: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:vertical "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}

void MainWindow::on_slider_3_sliderMoved(int position)
{

   ui->slider_3->setStyleSheet("QSlider::groove:vertical"
                               "{"
                               "width: 16px;border-radius:8px;"
                               "background: rgba(255, 0, 0,"+ QString::number(slope(position)) + ");"
                               "margin: 0px;"
                               "}"
                               "QSlider::handle:vertical "
                               "{"
                               "background: rgb(255, 255, 255);"
                               "width: 11px;"
                               "height: 11px;"
                               "margin: 1px 2px ;"
                               "border-radius:6px;"
                               "border: 1px solid rgb(120, 120, 120);}");
}

