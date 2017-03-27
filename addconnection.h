#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QWidget>
#include "directedgraph.h"
#include "engine.h"
namespace Ui {
class AddConnection;
}

class AddConnection : public QWidget
{
    Q_OBJECT

public:
    explicit AddConnection(QWidget *parent = 0);
    ~AddConnection();

public slots:
    void update(QObject * sender=NULL);
    void onApplyClicked();
signals:

    void changed(QObject * sender);
private:
    Ui::AddConnection *ui;
    DirectedGraph * source;
};

#endif // ADDCONNECTION_H
