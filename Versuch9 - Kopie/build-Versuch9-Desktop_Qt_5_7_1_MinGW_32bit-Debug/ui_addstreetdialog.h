/********************************************************************************
** Form generated from reading UI file 'addstreetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREETDIALOG_H
#define UI_ADDSTREETDIALOG_H

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

class Ui_AddStreetDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_city1;
    QLabel *label_2;
    QComboBox *comboBox_city2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddStreetDialog)
    {
        if (AddStreetDialog->objectName().isEmpty())
            AddStreetDialog->setObjectName(QStringLiteral("AddStreetDialog"));
        AddStreetDialog->resize(400, 300);
        formLayout = new QFormLayout(AddStreetDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(AddStreetDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_city1 = new QComboBox(AddStreetDialog);
        comboBox_city1->setObjectName(QStringLiteral("comboBox_city1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_city1);

        label_2 = new QLabel(AddStreetDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox_city2 = new QComboBox(AddStreetDialog);
        comboBox_city2->setObjectName(QStringLiteral("comboBox_city2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_city2);

        buttonBox = new QDialogButtonBox(AddStreetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(AddStreetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddStreetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddStreetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddStreetDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStreetDialog)
    {
        AddStreetDialog->setWindowTitle(QApplication::translate("AddStreetDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddStreetDialog", "Stadt 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddStreetDialog", "Stadt 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddStreetDialog: public Ui_AddStreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREETDIALOG_H
