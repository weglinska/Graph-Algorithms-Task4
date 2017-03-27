#include "connectionmatrixview.h"

ConnectionMatrixView::ConnectionMatrixView(QWidget *parent) : QWidget(parent)
{
    myLayout=new QVBoxLayout(this);
    this->setLayout(myLayout);
}

void ConnectionMatrixView::update(QObject * sender){
    Q_UNUSED(sender);
    source=Engine::getInstance()->getGraph();
    QLayoutItem *wItem;
    while (true){
        wItem=this->myLayout->takeAt(0);
        if(!wItem){
                break;
        }
        delete wItem->widget();
        delete wItem;
    }
    delete myLayout;

    myLayout=new QVBoxLayout(this);

    this->setLayout(myLayout);

    std::vector<std::vector<int> > connectionMatrix=source->getIncidenceMatrix();

    for(unsigned i=0;i<connectionMatrix.size();i++){
        QLabel * row=new QLabel(this);

        QString result(QString::number(i+1)+":\t");

        for(unsigned j=0;j<connectionMatrix[i].size();j++){
            result+="|";
            if(connectionMatrix[i][j]!=-1){
                result+=" ";
            }
            result=result+QString::number(connectionMatrix[i][j]);
        }
        result+="|";
        row->setText(result);
        myLayout->addWidget(row);
    }
}


