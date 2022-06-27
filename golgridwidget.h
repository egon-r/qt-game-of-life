#ifndef GOLGRIDWIDGET_H
#define GOLGRIDWIDGET_H

#include <QWidget>
#include "golgridmodel.h"
#include <QPainter>
#include <QMouseEvent>

class GolGridWidget : public QWidget
{
    Q_OBJECT

private:
    int gridHStep;
    int gridWStep;
    int stepSize;

private:
    void ToggleGridAt(QMouseEvent *event);

public:
    GolGridWidget(GolGridModel *model);
    GolGridModel *model;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GOLGRIDWIDGET_H
