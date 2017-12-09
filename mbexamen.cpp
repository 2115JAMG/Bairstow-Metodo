#include "mbexamen.h"
#include "ui_mbexamen.h"
#include <QString>
#include <qmath.h>
#include <cmath>
#include <qmessagebox.h> //librería de alerta de mensaje

MBexamen::MBexamen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MBexamen)
{
    ui->setupUi(this);
    //The interface connections to the program are created//conexiones dela interfaz con el programa creado.
        connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
        connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
        connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));

}

MBexamen::~MBexamen()
{
    delete ui;
}
//Enter the function to be evaluated//ingreso de la función que será evaluda
double MBexamen::funcion(double x){
    return (x*x*x*x*x)-3.5*(x*x*x*x)+2.75*(x*x*x)+2.125*(x*x)-3.875*x+1.25 ; //f(x)=(x^5)-3.5*(x^4)+2.75(x*x*x)-3.875*x+1.25
}

//read the values entered by the user//lee los valores que serán usados
void MBexamen::metodo(){
    QString temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8;
    double tol=ui->doubleSpinBox->value();
    double r=ui->doubleSpinBox_2->value();
    double s=ui->doubleSpinBox_3->value();
    double R,S,er,sr,a,x1,x2,det,A0,A1,A2,A3,A4,A5,b1,b0,b2,b3,b4,b5,c1,c2,c3,c4,c5,i,j,k;


    if(r==0 & s==0){
    QMessageBox msgBox;
    msgBox.setText("Usted no ingreso valores a R o S los cuales son fundamentales para que el método se realice (si no el método no funciona).");
    msgBox.exec();//shows a waring//muestra la advertencia
    }


A0=ui->doubleSpinBox_4->value();
A1=ui->doubleSpinBox_5->value();
A2=ui->doubleSpinBox_6->value();  //value of coefficients for variables A // valores de los coeficientes de las variables A
A3=ui->doubleSpinBox_7->value();
A4=ui->doubleSpinBox_8->value();
A5=ui->doubleSpinBox_9->value();

for(i=1;i<=tol;i++){
b5=A5;                     //se realiza el método de Bairstow en el cual se calsulan las raices de una función mayor a grado 2
b4=A4+(r*b5);              //en el que primero se calculan las "b" y después las "c" para así generar un arreglo matemático
b3=A3+(r*b4)+(s*b5);       //y poder obtener la raiz en X numero de iteraciones, tal es el caso de mi programa.
b2=A2+(r*b3)+(s*b4);
b1=A1+(r*b2)+(s*b3);       //the Bairstow method is performed in which the roots of a higher function are graded to grade 2
b0=A0+(r*b1)+(s*b2);       //in which first the "b" and then the "c" are calculated in order to generate a mathematical arrangement
c5=b5;                     //and be able to obtain the root in X number of iterations, such is the case of my program.
c4=b4+(r*c5);
c3=b3+(r*c4)+(s*c5);
c2=b2+(r*c3)+(s*c4);
c1=b1+(r*c2)+(s*c3);
det=(c2*c2)-(c3*c1);
R=(-(b1*c2)+(b0*c3))/det;
S=(-(b0*c2)+(b1*c1))/det;
k=r;
j=s;
r=k+R;
s=j+S;
a=a+1;
}

er=100*std::abs(R/r);//se obtiene el porcentaje de error
sr=100*std::abs(S/s);// you get the error percentage

x2=(-r-sqrt((r*r)+4*(0.5)))/2;//se obtienen las raices de los resultados finales
x1=(-r+sqrt((r*r)+4*(0.5)))/2;// the roots of the final results are obtained

//the result is generated en texto //los resultados son generados en texto
temp.append("R ").append(temp2.setNum(R)).append("\nS ").append(temp3.setNum(S)).append("\nNúmero de iteraciones: ").append(temp4.setNum(a)).append("\nPorcentaje de error er: ").append(temp5.setNum(er)).append("%").append("\nPorcentaje de error sr: ").append(temp6.setNum(sr)).append("%").append("\nRaíces: ").append(temp7.setNum(x1)).append(",").append(temp8.setNum(x2));
ui->textEdit->setText(temp);
}

//funtion "Borrar" is defined to clean the interface//la función "Borrar" es definida para limpiar la interface
void MBexamen::borrar(){
    ui->doubleSpinBox->setValue(0.0);
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(0.0);
    ui->doubleSpinBox_4->setValue(0.0);
    ui->doubleSpinBox_5->setValue(0.0);
    ui->doubleSpinBox_6->setValue(0.0);
    ui->doubleSpinBox_7->setValue(0.0);
    ui->doubleSpinBox_8->setValue(0.0);
    ui->doubleSpinBox_9->setValue(0.0);
    ui->textEdit->clear();
}


