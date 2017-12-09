#ifndef MBEXAMEN_H
#define MBEXAMEN_H

#include <QMainWindow>

namespace Ui {
class MBexamen;
}

class MBexamen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MBexamen(QWidget *parent = 0);
    ~MBexamen();
    double funcion(double x);

private:
    Ui::MBexamen *ui;

public slots:
    void metodo();
    void borrar();

};

#endif // MBEXAMEN_H
