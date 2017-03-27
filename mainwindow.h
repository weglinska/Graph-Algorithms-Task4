#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "engine.h"
#include "directedgraph.h"
#include "maxstronglyconnectedcomponent.h"
#include "shortestpaths.h"
#include "topologicalsort.h"
#include "dag.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_createNewGraphButton_clicked();

    void on_generate_clicked();
    void onGraphChanged(QObject * sender);

    void on_generateFromGraphToBF_clicked();

    void on_checkDistance_clicked();

    void on_johnsonApply_clicked();

    void on_floydWarshall_clicked();

    void on_sortTrigget_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
