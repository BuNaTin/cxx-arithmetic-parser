#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "source/Expression/Expression.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->input, &QLineEdit::textChanged, this, &MainWindow::update);
}

void MainWindow::update(const QString &str)
{
    std::cout << "NEW:" << str.toStdString() << '\n';
    Expression expr(str.toStdString());
    auto [result, code] = expr.Calc();
    if (code)
    {
        ui->output->setText(QString::number(result));
    }
    else
    {
        ui->output->setText("We can't solve this task");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
