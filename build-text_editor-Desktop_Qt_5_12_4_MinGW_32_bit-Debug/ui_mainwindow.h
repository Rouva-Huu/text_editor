/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QAction *action_7;
    QAction *action_9;
    QAction *action_10;
    QAction *action_12;
    QAction *action_13;
    QAction *action_15;
    QAction *action_16;
    QAction *action_17;
    QAction *action_18;
    QAction *action_19;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1008, 719);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon2);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon3);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_5->setIcon(icon4);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_7->setIcon(icon5);
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_9->setIcon(icon6);
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QString::fromUtf8("action_10"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_10->setIcon(icon7);
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QString::fromUtf8("action_12"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_12->setIcon(icon8);
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QString::fromUtf8("action_13"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/find_and_replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_13->setIcon(icon9);
        action_15 = new QAction(MainWindow);
        action_15->setObjectName(QString::fromUtf8("action_15"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/img/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_15->setIcon(icon10);
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QString::fromUtf8("action_16"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/img/table.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_16->setIcon(icon11);
        action_17 = new QAction(MainWindow);
        action_17->setObjectName(QString::fromUtf8("action_17"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/img/font_size.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_17->setIcon(icon12);
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QString::fromUtf8("action_18"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/img/text_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_18->setIcon(icon13);
        action_19 = new QAction(MainWindow);
        action_19->setObjectName(QString::fromUtf8("action_19"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/img/paint_palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_19->setIcon(icon14);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1008, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        MainWindow->insertToolBarBreak(toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_4);
        menu->addAction(action_5);
        menu_2->addAction(action_9);
        menu_2->addAction(action_10);
        menu_2->addSeparator();
        menu_2->addAction(action_12);
        menu_2->addAction(action_13);
        menu_2->addSeparator();
        menu_2->addAction(action_15);
        menu_2->addAction(action_7);
        menu_3->addAction(action_16);
        menu_3->addAction(action_19);
        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addSeparator();
        toolBar->addAction(action_4);
        toolBar->addSeparator();
        toolBar->addAction(action_12);
        toolBar->addAction(action_13);
        toolBar->addSeparator();
        toolBar->addAction(action_15);
        toolBar->addAction(action_7);
        toolBar_2->addAction(action_17);
        toolBar_2->addAction(action_18);
        toolBar_3->addAction(action_16);
        toolBar_3->addAction(action_19);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Text Editor", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        action_4->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
        action_7->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_7->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        action_9->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        action_10->setText(QApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\270\321\202\321\214", nullptr));
        action_12->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        action_13->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        action_15->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_15->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        action_16->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 ", nullptr));
        action_17->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\210\321\200\320\270\321\204\321\202", nullptr));
        action_18->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        action_19->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\273\320\270\321\202\321\200\320\260", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
