#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include "directedgraph.h"
#include "listviewitem.h"
#include "engine.h"
class ListView : public QWidget
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = 0);
signals:
    void changed(QObject * sender);
public slots:
    void update(QObject * sender = NULL);
    void removeRequest(int firstID,int secondID);
private:
    QVBoxLayout * myLayout;
    DirectedGraph * source;
};

#endif // LISTVIEW_H
