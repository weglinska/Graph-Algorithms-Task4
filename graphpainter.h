#ifndef GRAPHPAINTER_H
#define GRAPHPAINTER_H

#include <QWidget>
#include <QMatrix>
#include <QColor>
#include <vector>
#include <math.h>
#include <QPainter>
#include "directedgraph.h"
#include "engine.h"
#define PI 3.1415
class GraphPainter : public QWidget
{
    Q_OBJECT
public:
    explicit GraphPainter(QWidget *parent = 0);
    void setPointColor(QColor pointC);
    void setLineColor(QColor lineC);
    void enableLabels(){showLabels=true;}
    void disableLabels(){showLabels=false;}
    void paintEvent(QPaintEvent *);
signals:


public slots:
    void update(QObject * sender=NULL);



private:
    QColor pathColor;
    QColor pointColor;
    QColor lineColor;
    bool showLabels;
    DirectedGraph * pointerToGraphMatrix;
};

#endif // GRAPHPAINTER_H

