#include "listview.h"

ListView::ListView(QWidget *parent) : QWidget(parent)
{
    myLayout=new QVBoxLayout(this);
    this->setLayout(myLayout);
}


void ListView::update(QObject * sender){
    Q_UNUSED (sender);

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

    std::vector<std::vector<int> > list=source->getAdjacencyList();
    for(unsigned i=0;i<list.size();i++){
        if(list[i].size()>0){
            ListViewItem * item=new ListViewItem(this,i,list[i],source->getVerticesNumber());
            connect(item,SIGNAL(remove(int,int)),this,SLOT(removeRequest(int,int)));
            item->setContentsMargins(0,-12,0,-12);
            item->setMaximumHeight(20);
            myLayout->addWidget(item,Qt::AlignTop);
        }
    }
}
void ListView::removeRequest(int firstID, int secondID){
    source->_adjacencyMatrix[secondID][firstID]=false;
    source->_weightMatrix[secondID][firstID]=0;
    emit changed(this);
}

