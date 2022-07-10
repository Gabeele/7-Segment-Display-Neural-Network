#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mlp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MultiLayerPerceptron* mlp;
    vector<double> input = { 0,0,0,0,0,0,0 };
    double MSE = 0.0;
    int epochsAmount = 0;

private slots:
    void calculate_NN();
void writeToLabel(int rounded, double raw);

    void on_slider_2_sliderReleased();

    void on_learnBtn_clicked();

    void on_slider_3_sliderReleased();

    void on_slider_4_sliderReleased();

    void on_slider_5_sliderReleased();

    void on_slider_6_sliderReleased();

    void on_slider_7_sliderReleased();

    void on_slider_1_sliderReleased();

    void on_resetBtn_clicked();

    void reset_UI();


    void on_slider_3_sliderMoved(int position);
    void on_slider_2_sliderMoved(int position);
    void on_slider_5_sliderMoved(int position);
    void on_slider_6_sliderMoved(int position);
    void on_slider_1_sliderMoved(int position);
    void on_slider_4_sliderMoved(int position);
    void on_slider_7_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
