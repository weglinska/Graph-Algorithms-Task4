#ifndef MATRIXVIEVCELL_H
#define MATRIXVIEVCELL_H
#include <QLineEdit>
#include <QDebug>

class MatrixVievCell : public QLineEdit
{
    Q_OBJECT
public:
    explicit MatrixVievCell(QPoint _coordinates,int value,QWidget *parent=0);
    ~ MatrixVievCell(){

    }

private slots:
    void sthChanged(QString);

signals:
    void changed(QPoint coordinates,int value);
private:
    QPoint coordinates;

};

#endif // MATRIXVIEVCELL_H
