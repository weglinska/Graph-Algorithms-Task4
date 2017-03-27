#include "listviewitem.h"

ListViewItem::ListViewItem(QWidget *parent,int ID,std::vector<int> neightboors,int size): QWidget(parent)
{
    Q_UNUSED(size);
    this->ID=ID;
    myLayout=new QHBoxLayout(this);
    this->setLayout(myLayout);
    myLayout->addWidget(new QLabel(QString::number(ID+1)+"=>",this));

    for(unsigned i=0;i<neightboors.size();i++){
        listViewRemoveButton * label=new listViewRemoveButton(this,neightboors[i]);
        connect(label,SIGNAL(remove(int)),this,SLOT(removeRequest(int)));
        myLayout->addWidget(label);

        if(i<(neightboors.size()-1)){
            myLayout->addWidget(new QLabel(":",this));
        }
    }
    myLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed));
}
void ListViewItem::removeRequest(int id){
    emit remove(id,ID);
}

ListViewItem::~ListViewItem(){
    QLayoutItem *wItem;
    while (true){
        wItem =myLayout->takeAt(0);
        if(wItem==NULL){
            break;
        }
        delete wItem->widget();
        delete wItem;
    }
    delete myLayout;
}

