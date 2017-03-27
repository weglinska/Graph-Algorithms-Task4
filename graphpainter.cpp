#include "graphpainter.h"

GraphPainter::GraphPainter(QWidget *parent) : QWidget(parent)
{
    pointerToGraphMatrix=NULL;
    pointColor=QColor(Qt::red);
    lineColor=QColor(Qt::gray);
    pathColor=QColor(Qt::green);
    showLabels=true;
}

void GraphPainter::update(QObject * sender){
    Q_UNUSED (sender);
    pointerToGraphMatrix=Engine::getInstance()->getGraph();
    repaint();
}

void GraphPainter::paintEvent(QPaintEvent * event){
    Q_UNUSED(event);
    if(pointerToGraphMatrix==NULL) return;

    QPoint widgetCenter(this->width()/2,this->height()/2);

    QVector<QPoint> pointsCordinates;
    int numberOfElements=pointerToGraphMatrix->getVerticesNumber();

    float angleStep=2.0*PI/numberOfElements;
    float radius=width()>height()?height():width();

    for(int index=0;index<numberOfElements;index++){
        QPoint point;

        point.setX(sin(angleStep*index)*radius/2.5);
        point.setY(cos(angleStep*index)*radius/2.5);
        pointsCordinates.push_back(point+widgetCenter);
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(lineColor,2));


    for(int index=0;index<numberOfElements;index++){
        for(int index2=index;index2<numberOfElements;index2++){
            if((*pointerToGraphMatrix)._adjacencyMatrix[index][index2] || (*pointerToGraphMatrix)._adjacencyMatrix[index2][index]){
                if((*pointerToGraphMatrix)._adjacencyMatrix[index][index2] && (*pointerToGraphMatrix)._adjacencyMatrix[index2][index]){
                    painter.setPen(Qt::red);
                }
                else if((*pointerToGraphMatrix)._adjacencyMatrix[index][index2]){
                    painter.setPen(Qt::blue);
                }
                else{
                    painter.setPen(Qt::green);
                }

                painter.drawLine(pointsCordinates[index],pointsCordinates[index2]);

            }
        }
    }

    painter.setPen(QPen(pathColor,2));


    painter.setPen(Qt::white);
    int ID=1;
    for(int index=0;index<numberOfElements;index++){
        // idzie po górnym trójkącie
        for(int index2=index;index2<numberOfElements;index2++){
            if((*pointerToGraphMatrix)._adjacencyMatrix[index][index2] || (*pointerToGraphMatrix)._adjacencyMatrix[index2][index]){
                QPoint textCord((pointsCordinates[index].x()+pointsCordinates[index2].x())/2,(pointsCordinates[index].y()+pointsCordinates[index2].y())/2);

                QString text;
                if((*pointerToGraphMatrix)._adjacencyMatrix[index][index2]){
                    text=QString::number(index+1)+"=>"+QString::number(index2+1)+":"+QString::number((*pointerToGraphMatrix)._weightMatrix[index][index2] );
                    painter.drawText(textCord,text);
                    textCord.setY(textCord.y()+10);
                }

                if((*pointerToGraphMatrix)._adjacencyMatrix[index2][index]){
                    text=QString::number(index2+1)+"=>"+QString::number(index+1)+":"+QString::number((*pointerToGraphMatrix)._weightMatrix[index2][index] );
                    painter.drawText(textCord,text);
                }
                ID++;
            }
        }
    }
    for(int index=0;index<numberOfElements;index++){
        QPoint point=pointsCordinates[index];

        painter.setPen(QPen(pointColor,2));
        painter.drawEllipse(point,3,3);

        if(showLabels){
            painter.setPen(Qt::black);
            painter.drawText(point+QPoint(4,-4),QString::number(index+1));
        }
    }




}

void GraphPainter::setPointColor(QColor pointC){
    pointColor=pointC;
}

void GraphPainter::setLineColor(QColor lineC){
    lineColor=lineC;
}
