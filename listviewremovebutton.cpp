#include "listviewremovebutton.h"

listViewRemoveButton::listViewRemoveButton(QWidget *parent,int ID) : QPushButton(parent)
{
    setStyleSheet("QPushButton { border: none }");
    setText(QString::number(ID+1));
    this->ID=ID;
    connect(this,SIGNAL(clicked(bool)),this,SLOT(onClicked()));

}
void listViewRemoveButton::onClicked(){
    emit remove(ID);
}
