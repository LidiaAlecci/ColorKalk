#include <QApplication>
#include <calculator.h>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Calculator* mainWindow= new Calculator();
    mainWindow->show();
    return app.exec();
}
