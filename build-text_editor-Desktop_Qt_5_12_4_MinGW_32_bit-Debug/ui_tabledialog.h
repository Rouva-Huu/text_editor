/********************************************************************************
** Form generated from reading UI file 'tabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEDIALOG_H
#define UI_TABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_TableDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *TableDialog)
    {
        if (TableDialog->objectName().isEmpty())
            TableDialog->setObjectName(QString::fromUtf8("TableDialog"));
        TableDialog->resize(240, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableDialog->sizePolicy().hasHeightForWidth());
        TableDialog->setSizePolicy(sizePolicy);
        TableDialog->setMinimumSize(QSize(240, 200));
        TableDialog->setMaximumSize(QSize(300, 200));
        TableDialog->setBaseSize(QSize(200, 200));
        gridLayout = new QGridLayout(TableDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        label_3 = new QLabel(TableDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(TableDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox = new QComboBox(TableDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        label = new QLabel(TableDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TableDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        spinBox = new QSpinBox(TableDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(TableDialog);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);


        retranslateUi(TableDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TableDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TableDialog);
    } // setupUi

    void retranslateUi(QDialog *TableDialog)
    {
        TableDialog->setWindowTitle(QApplication::translate("TableDialog", "\320\222\321\201\321\202\320\260\320\262\320\272\320\260 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        label_3->setText(QApplication::translate("TableDialog", "\320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_2->setText(QApplication::translate("TableDialog", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\321\200\320\276\320\272:", nullptr));
        comboBox->setItemText(0, QApplication::translate("TableDialog", "\320\237\320\276 \321\206\320\265\320\275\321\202\321\200\321\203", nullptr));
        comboBox->setItemText(1, QApplication::translate("TableDialog", "\320\237\320\276 \320\273\320\265\320\262\320\276\320\274\321\203 \320\272\321\200\320\260\321\216", nullptr));
        comboBox->setItemText(2, QApplication::translate("TableDialog", "\320\237\320\276 \320\277\321\200\320\260\320\262\320\276\320\274\321\203 \320\272\321\200\320\260\321\216", nullptr));

        label->setText(QApplication::translate("TableDialog", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableDialog: public Ui_TableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEDIALOG_H
