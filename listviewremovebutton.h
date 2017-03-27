#ifndef LISTVIEWREMOVEBUTTON_H
#define LISTVIEWREMOVEBUTTON_H

#include <QPushButton>

class listViewRemoveButton : public QPushButton
{
    Q_OBJECT
    int ID;
public:
    explicit listViewRemoveButton(QWidget *parent,int ID);
signals:
    void remove(int ID);
public slots:
    void onClicked();
};

#endif // LISTVIEWREMOVEBUTTON_H
