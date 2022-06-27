#include "golgridwidget.h"

void GolGridWidget::ToggleGridAt(QMouseEvent *event)
{
    int x = event->pos().rx() / stepSize;
    int y = event->pos().ry() / stepSize;

    if(model->GetStateAt(x,y) == alive)
    {
        model->SetStateAt(x,y, dead);
    }else{
        model->SetStateAt(x,y, alive);
    }
    this->repaint();
}

GolGridWidget::GolGridWidget(GolGridModel *model)
{
    this->model = model;
}

void GolGridWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    gridHStep = this->height() / model->GetBoardSize();
    gridWStep = this->width() / model->GetBoardSize();

    stepSize = (gridHStep > gridWStep) ? gridWStep : gridHStep;

    for(int x = 0; x < model->GetBoardSize(); x++)
    {
        for(int y = 0; y < model->GetBoardSize(); y++)
        {
            painter.fillRect(x*stepSize, y*stepSize, stepSize, stepSize, Qt::gray);
            if(model->GetStateAt(x,y) == dead)
            {
                painter.fillRect(x*stepSize+1, y*stepSize+1, stepSize-1, stepSize-1, Qt::black);
            }else{
                painter.fillRect(x*stepSize+1, y*stepSize+1, stepSize-1, stepSize-1, Qt::white);
            }
        }
    }
}

void GolGridWidget::mousePressEvent(QMouseEvent *event)
{
    ToggleGridAt(event);
}
