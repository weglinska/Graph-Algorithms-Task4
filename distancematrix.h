#ifndef DISTANCEMATRIX_H
#define DISTANCEMATRIX_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "distancematrix.h"
#include "consistent.h"
#include "directedgraph.h"

#include <QLabel>
class DistanceMatrix : public QWidget
{
    Q_OBJECT
public:
    explicit DistanceMatrix(QWidget *parent = 0);

signals:

public slots:
    void update(QObject *);
private:
    DirectedGraph * dataPointer;
    QGridLayout * myLayout;
};

#endif // DISTANCEMATRIX_H
