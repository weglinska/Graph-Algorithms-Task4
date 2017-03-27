#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->matrixView,SIGNAL(changed(QObject*)),Engine::getInstance(),SLOT(updateGraph(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->matrixView,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->neLIST,SLOT(update(QObject*)));
    connect(ui->neLIST,SIGNAL(changed(QObject*)),Engine::getInstance(),SLOT(updateGraph(QObject*)));
    connect(ui->addConnectionView,SIGNAL(changed(QObject*)),Engine::getInstance(),SLOT(updateGraph(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->addConnectionView,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->connectionMatrix,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->graphView,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),this,SLOT(onGraphChanged(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->distanceMatrix,SLOT(update(QObject*)));
}

void MainWindow::onGraphChanged(QObject *sender){
    qDebug()<<"weq";
    std::vector < std::vector<int> > stronglyComponents=Engine::getInstance()->getGraph()->getStronglyConnectedComponents();
    QString result="";
    for(int i=0;i<stronglyComponents.size();i++){
        for(int j=0;j<stronglyComponents.at(i).size();j++){
            if(j!=0){
                result+=",";
            }
            result+=QString::number(stronglyComponents.at(i).at(j));
        }
        result+="<br>";
    }
    ui->strongComponents->setText(result);

    std::vector<std::vector<int> > cycles =Engine::getInstance()->getGraph()->getCycles();

    result="";
    for(int i=0;i<cycles.size();i++){
        for(int j=0;j<cycles.at(i).size();j++){
            if(j!=0){
                result+=",";
            }
            result+=QString::number(cycles.at(i).at(j));
        }
        result+="<br>";
    }
    ui->cycles->setText(result);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createNewGraphButton_clicked()
{
    Engine::getInstance()->setGraph(new DirectedGraph(ui->vertsNumberSpin->value()));

}

void MainWindow::on_generate_clicked()
{

    DirectedGraph * tmp=DirectedGraph::randomConsistentDiGraph(ui->vertexNumberInGenerator->value());
    Engine::getInstance()->setGraph(tmp);
}

void MainWindow::on_generateFromGraphToBF_clicked()
{
    Engine::getInstance()->setGraph(MaxStronglyConnectedComponent::getMaxStronglyConnectedComponent(Engine::getInstance()->getGraph()));
}

void MainWindow::on_checkDistance_clicked()
{
    int vertexID=ui->BF_vertex_ID->value();
    QString result="";
    for(int i=0;i<Engine::getInstance()->getGraph()->getVerticesNumber();i++){
        result+=QString::number(vertexID+1);
        result+="=>";
        result+=QString::number(i+1);
        result+=" : ";
        result+=QString::number(ShortestPaths::bellmanFord(Engine::getInstance()->getGraph(),vertexID,i));
        result+="<br>";

    }
    ui->distanceLabelBF->setText(result);
}

void MainWindow::on_johnsonApply_clicked()
{
    ShortestPaths::johnson(Engine::getInstance()->getGraph());
    Engine::getInstance()->updateGraph(this);

}

void MainWindow::on_floydWarshall_clicked()
{
    ShortestPaths::floydWarshall(Engine::getInstance()->getGraph());
    Engine::getInstance()->updateGraph(this);
}

void MainWindow::on_sortTrigget_clicked()
{

    //DirectedAcyclicGraph::dagCreator(Engine::getInstance()->getGraph());
    Engine::getInstance()->setGraph(DirectedAcyclicGraph::dagCreator(Engine::getInstance()->getGraph()));
    std::list <int> sort=TopologicalSort::getTopologicalSort(Engine::getInstance()->getGraph());
    QString result="Wynik sortowania topologicznego <br>";


    for(int i=0; i<sort.size();i++){
        result+=" ";
        result+=QString::number(sort.front());
        sort.pop_front();
    }
    ui->sortResult->setText(result);

}
