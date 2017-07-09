#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "city.h"
#include "map.h"

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
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButtonTestDrawCity_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;

#endif // MAINWINDOW_H
