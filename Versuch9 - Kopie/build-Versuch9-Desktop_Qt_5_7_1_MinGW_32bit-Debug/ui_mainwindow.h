/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_add_city;
    QLabel *label_Eingabe;
    QPushButton *pushButton_test_dijkstra;
    QPushButton *pushButton_test_draw_City;
    QCheckBox *checkBox;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_teste_was;
    QLineEdit *lineEdit_teste_was;
    QPushButton *pushButton_test_add_street;
    QPushButton *pushButton_fill_map;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_test_abstractMap;
    QPushButton *pushButton_test_draw_street;
    QPushButton *pushButton_show_dijkstra_dialog;
    QPushButton *pushButton_add_street;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 273);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName(QStringLiteral("actionClear_Scene"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_add_city = new QPushButton(centralWidget);
        pushButton_add_city->setObjectName(QStringLiteral("pushButton_add_city"));

        gridLayout->addWidget(pushButton_add_city, 7, 0, 1, 1);

        label_Eingabe = new QLabel(centralWidget);
        label_Eingabe->setObjectName(QStringLiteral("label_Eingabe"));

        gridLayout->addWidget(label_Eingabe, 0, 0, 1, 1);

        pushButton_test_dijkstra = new QPushButton(centralWidget);
        pushButton_test_dijkstra->setObjectName(QStringLiteral("pushButton_test_dijkstra"));

        gridLayout->addWidget(pushButton_test_dijkstra, 10, 0, 1, 1);

        pushButton_test_draw_City = new QPushButton(centralWidget);
        pushButton_test_draw_City->setObjectName(QStringLiteral("pushButton_test_draw_City"));
        pushButton_test_draw_City->setEnabled(true);
        pushButton_test_draw_City->setVisible(false);

        gridLayout->addWidget(pushButton_test_draw_City, 4, 0, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 14, 1);

        pushButton_teste_was = new QPushButton(centralWidget);
        pushButton_teste_was->setObjectName(QStringLiteral("pushButton_teste_was"));

        gridLayout->addWidget(pushButton_teste_was, 3, 0, 1, 1);

        lineEdit_teste_was = new QLineEdit(centralWidget);
        lineEdit_teste_was->setObjectName(QStringLiteral("lineEdit_teste_was"));
        lineEdit_teste_was->setClearButtonEnabled(true);

        gridLayout->addWidget(lineEdit_teste_was, 2, 0, 1, 1);

        pushButton_test_add_street = new QPushButton(centralWidget);
        pushButton_test_add_street->setObjectName(QStringLiteral("pushButton_test_add_street"));
        pushButton_test_add_street->setEnabled(true);
        pushButton_test_add_street->setVisible(false);

        gridLayout->addWidget(pushButton_test_add_street, 6, 0, 1, 1);

        pushButton_fill_map = new QPushButton(centralWidget);
        pushButton_fill_map->setObjectName(QStringLiteral("pushButton_fill_map"));

        gridLayout->addWidget(pushButton_fill_map, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        pushButton_test_abstractMap = new QPushButton(centralWidget);
        pushButton_test_abstractMap->setObjectName(QStringLiteral("pushButton_test_abstractMap"));

        gridLayout->addWidget(pushButton_test_abstractMap, 9, 0, 1, 1);

        pushButton_test_draw_street = new QPushButton(centralWidget);
        pushButton_test_draw_street->setObjectName(QStringLiteral("pushButton_test_draw_street"));
        pushButton_test_draw_street->setEnabled(true);
        pushButton_test_draw_street->setVisible(false);

        gridLayout->addWidget(pushButton_test_draw_street, 5, 0, 1, 1);

        pushButton_show_dijkstra_dialog = new QPushButton(centralWidget);
        pushButton_show_dijkstra_dialog->setObjectName(QStringLiteral("pushButton_show_dijkstra_dialog"));

        gridLayout->addWidget(pushButton_show_dijkstra_dialog, 11, 0, 1, 1);

        pushButton_add_street = new QPushButton(centralWidget);
        pushButton_add_street->setObjectName(QStringLiteral("pushButton_add_street"));

        gridLayout->addWidget(pushButton_add_street, 12, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Alt+E", Q_NULLPTR));
        actionClear_Scene->setText(QApplication::translate("MainWindow", "&Clear Scene", Q_NULLPTR));
        actionClear_Scene->setShortcut(QApplication::translate("MainWindow", "Alt+S", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
        pushButton_add_city->setText(QApplication::translate("MainWindow", "Stadt hinzuf\303\274gen", Q_NULLPTR));
        label_Eingabe->setText(QApplication::translate("MainWindow", "Ihre Eingabe", Q_NULLPTR));
        pushButton_test_dijkstra->setText(QApplication::translate("MainWindow", "Test Dijkstra", Q_NULLPTR));
        pushButton_test_draw_City->setText(QApplication::translate("MainWindow", "TestDrawCity", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Test Buttons", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_teste_was->setToolTip(QApplication::translate("MainWindow", "Eingabe best\303\244tigen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_teste_was->setText(QApplication::translate("MainWindow", "Enter", Q_NULLPTR));
        lineEdit_teste_was->setPlaceholderText(QApplication::translate("MainWindow", "Ihre Eingabe", Q_NULLPTR));
        pushButton_test_add_street->setText(QApplication::translate("MainWindow", "TestAddStreet", Q_NULLPTR));
        pushButton_fill_map->setText(QApplication::translate("MainWindow", "Map f\303\274llen", Q_NULLPTR));
        pushButton_test_abstractMap->setText(QApplication::translate("MainWindow", "Test Abstract Map", Q_NULLPTR));
        pushButton_test_draw_street->setText(QApplication::translate("MainWindow", "TestDrawStreet", Q_NULLPTR));
        pushButton_show_dijkstra_dialog->setText(QApplication::translate("MainWindow", "Weg suchen", Q_NULLPTR));
        pushButton_add_street->setText(QApplication::translate("MainWindow", "Stra\303\237e hinzuf\303\274gen", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", Q_NULLPTR));
        menuScene->setTitle(QApplication::translate("MainWindow", "S&cene", Q_NULLPTR));
        menuInfo->setTitle(QApplication::translate("MainWindow", "I&nfo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
