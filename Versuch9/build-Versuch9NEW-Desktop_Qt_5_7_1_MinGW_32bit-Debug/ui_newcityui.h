/********************************************************************************
** Form generated from reading UI file 'newcityui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCITYUI_H
#define UI_NEWCITYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newCityUI
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_city_name;
    QLabel *label_2;
    QLineEdit *lineEdit_city_x;
    QLabel *label_3;
    QLineEdit *lineEdit_city_y;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newCityUI)
    {
        if (newCityUI->objectName().isEmpty())
            newCityUI->setObjectName(QStringLiteral("newCityUI"));
        newCityUI->resize(400, 300);
        formLayout = new QFormLayout(newCityUI);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(newCityUI);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_city_name = new QLineEdit(newCityUI);
        lineEdit_city_name->setObjectName(QStringLiteral("lineEdit_city_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_city_name);

        label_2 = new QLabel(newCityUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_city_x = new QLineEdit(newCityUI);
        lineEdit_city_x->setObjectName(QStringLiteral("lineEdit_city_x"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_city_x);

        label_3 = new QLabel(newCityUI);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_city_y = new QLineEdit(newCityUI);
        lineEdit_city_y->setObjectName(QStringLiteral("lineEdit_city_y"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_city_y);

        buttonBox = new QDialogButtonBox(newCityUI);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(newCityUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), newCityUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newCityUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(newCityUI);
    } // setupUi

    void retranslateUi(QDialog *newCityUI)
    {
        newCityUI->setWindowTitle(QApplication::translate("newCityUI", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("newCityUI", "Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("newCityUI", "X", Q_NULLPTR));
        label_3->setText(QApplication::translate("newCityUI", "Y", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newCityUI: public Ui_newCityUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCITYUI_H
