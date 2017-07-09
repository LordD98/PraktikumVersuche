/********************************************************************************
** Form generated from reading UI file 'dijkstradialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRADIALOG_H
#define UI_DIJKSTRADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DijkstraDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_city1;
    QLabel *label_2;
    QComboBox *comboBox_city2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DijkstraDialog)
    {
        if (DijkstraDialog->objectName().isEmpty())
            DijkstraDialog->setObjectName(QStringLiteral("DijkstraDialog"));
        DijkstraDialog->resize(400, 300);
        formLayout = new QFormLayout(DijkstraDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DijkstraDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_city1 = new QComboBox(DijkstraDialog);
        comboBox_city1->setObjectName(QStringLiteral("comboBox_city1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_city1);

        label_2 = new QLabel(DijkstraDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_city2 = new QComboBox(DijkstraDialog);
        comboBox_city2->setObjectName(QStringLiteral("comboBox_city2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_city2);

        buttonBox = new QDialogButtonBox(DijkstraDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(DijkstraDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DijkstraDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DijkstraDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DijkstraDialog);
    } // setupUi

    void retranslateUi(QDialog *DijkstraDialog)
    {
        DijkstraDialog->setWindowTitle(QApplication::translate("DijkstraDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DijkstraDialog", "Stadt 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("DijkstraDialog", "Stadt 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DijkstraDialog: public Ui_DijkstraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRADIALOG_H
