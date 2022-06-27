#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "golgridmodel.h"
#include "golgridwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTimer *IterTimer;

private slots:
    void on_pushButton_clicked();
    void IterTimerUpdate();

    void on_IterationDelay_sliderMoved(int position);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    GolGridModel *golGrid;
    GolGridWidget *golWidget;
    QThread *iterationThread;
};

#endif // MAINWINDOW_H
