#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&(this->scene));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
	QString qstr = ui->lineEdit_teste_was->text();
	bool ok = false;
	int i = qstr.toInt(&ok);
	if(ok)
	{
		qDebug() << i+4;
	}
    int ileft = ui->graphicsView->rect().left(),
        iwidth = ui->graphicsView->rect().width(),
        itop = ui->graphicsView->rect().height(),
        iheight = ui->graphicsView->rect().bottom();
    this->scene.addRect(ileft+qrand()*(iwidth-80)/RAND_MAX, itop+qrand()*(iheight-28)/RAND_MAX, 10+qrand()*90/RAND_MAX, 10+qrand()*90/RAND_MAX);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionClear_Scene_triggered()
{
    this->scene.clear();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About: Streetplanner", "Ein einfacher Streetplanner.\nEntwickelt im Rahmen des Praktikums Informatik 1.");
}

void MainWindow::on_pushButtonTestDrawCity_clicked()
{
    City c1("Dresden", 300, 100);
    City c2("Berlin", 200, 50);
    c1.draw(this->scene);
    c2.draw(this->scene);
}

/*void MainWindow::on_pushButton_Test_Map_clicked()
{
    City c1("city c1", 20,50);
    this->map.addCity(&c1);
    this->map.draw(this->scene);
}*/
