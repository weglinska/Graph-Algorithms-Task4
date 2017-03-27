#include "matrixvievcell.h"

MatrixVievCell::MatrixVievCell(QPoint _coordinates,int value,QWidget *parent):QLineEdit(parent)
{
    coordinates=_coordinates;
    //setInputMask("9");

    setMaximumSize(30,50);
    setStyleSheet("QLineEdit { border: none }");
    setText(QString::number(value));
    connect(this,SIGNAL(textChanged(QString)),this,SLOT(sthChanged(QString)));
}

void MatrixVievCell::sthChanged(QString str){
    if(str.length()!=0){
        str=this->text();
        emit changed(coordinates,str.toInt());
    }
}
