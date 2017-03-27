#ifndef MATRIXVIEW_H
#define MATRIXVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "matrixvievcell.h"
#include "engine.h"

class MatrixView : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixView(QWidget *parent = 0);
signals:
    void changed(QObject * sender);
public slots:
    void cellChanged(QPoint coordinates,int value);
    void update(QObject * sender=NULL);
private:
    DirectedGraph * dataPointer;
    QGridLayout * myLayout;
};

#endif // MATRIXVIEW_H
