#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->appendPlainText("Enter text");
    list = new QStringList();
    model = new QStringListModel(this);
}

MainWindow::~MainWindow()
{
    delete list;
    delete model;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->plainTextEdit->toPlainText() == "")
        return;
    list->append(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit->clear();
    model->setStringList(*list);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_pushButton_2_clicked()
{
    list->append("BOT:   RANDOM MESSAGE...");
    model->setStringList(*list);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
