
#include "source/Expression/Expression.h"

#include "gui/mainwindow.h"
#include <QApplication>

#include <string>
#include <iostream>

// Test file
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;

    window.show();

    return a.exec();
    return 0;
}