#ifndef LISTVIEWITEM_H
#define LISTVIEWITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include "directedgraph.h"
#include "listviewremovebutton.h"
#include <QLabel>
#include <QSpacerItem>
class ListViewItem : public QWidget
{
    Q_OBJECT
public:
    explicit ListViewItem(QWidget *parent,int ID,std::vector<int> neightboors,int size);
    ~ListViewItem();
signals:
    void remove(int firstID,int secondID);
public slots:
    void removeRequest(int id);
private:
    QHBoxLayout * myLayout;
    int ID;
};

#endif // LISTVIEWITEM_H
