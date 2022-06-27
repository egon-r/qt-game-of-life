#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    golGrid = new GolGridModel(20);
    golWidget = new GolGridWidget(golGrid);
    ui->centralWidget->layout()->addWidget(golWidget);

    IterTimer = new QTimer();
    connect(IterTimer,SIGNAL(timeout()), this, SLOT(IterTimerUpdate()));

    golGrid->RandomizeBoardState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::IterTimerUpdate()
{
    golGrid->NextIteration();
    golWidget->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    if(IterTimer->isActive())
    {
        IterTimer->stop();
        ui->pushButton->setText("Start");
    }else{
        IterTimer->start(ui->IterationDelay->value());
        ui->pushButton->setText("Stop");
    }
}

void MainWindow::on_IterationDelay_sliderMoved(int position)
{
    ui->IterationDelayText->setText(QString::number(position));

    if(IterTimer->isActive())
    {
        IterTimer->stop();
        IterTimer->setInterval(position);
        IterTimer->start();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    golGrid->ResizeBoard(ui->BoardSize->value());
    golGrid->RandomizeBoardState();
    golWidget->repaint();
}
