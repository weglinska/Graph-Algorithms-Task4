#include "addconnection.h"
#include "ui_addconnection.h"

AddConnection::AddConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddConnection)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(onApplyClicked()));
}

AddConnection::~AddConnection()
{
    delete ui;
}

void AddConnection::update(QObject * sender){
    if(sender!=this){
        this->source=Engine::getInstance()->getGraph();
        ui->first->clear();
        ui->second->clear();
        for(int i=0;i<source->getVerticesNumber();i++){
            ui->first->addItem(QString::number(i+1));
            ui->second->addItem(QString::number(i+1));
        }
    }
}
void AddConnection::onApplyClicked(){
    if((ui->first->currentText().toInt()-1) !=(ui->second->currentText().toInt()-1)){
        source->_adjacencyMatrix[ui->first->currentText().toInt()-1][ui->second->currentText().toInt()-1]=true;
        source->_weightMatrix[ui->first->currentText().toInt()-1][ui->second->currentText().toInt()-1]=ui->connectionWeight->value();

        emit changed(this);
    }
}
