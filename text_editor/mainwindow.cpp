#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "tabledialog.h"
#include "declarations.h"
#include "editor.h"

#include <QStandardPaths>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileManager = new FileManager(ui->tabWidget, NULL);
    editor = new Editor(fileManager);
}

MainWindow::~MainWindow()
{
    delete editor;
    delete fileManager;
    delete ui;
}

void MainWindow::on_action_triggered() // creating a new file
{
    fileManager->createNewFile();
}

void MainWindow::on_action_2_triggered() // open existing file
{
    fileManager->openFile();
}

void MainWindow::on_action_4_triggered() // save to existing path
{
    fileManager->saveFile();
}

void MainWindow::on_action_5_triggered() // save to specified path
{
    fileManager->saveFileAs();
}

void MainWindow::on_action_16_triggered() // addind a table
{
    tableDialog = new TableDialog(this);
    tableDialog->setModal(true);
    tableDialog->exec();

    QTextTableFormat tableFormat;
    switch (tableDialog->tableAlignment()) {
    case 0:
        tableFormat.setAlignment(Qt::AlignCenter);
        break;
    case 1:
        tableFormat.setAlignment(Qt::AlignLeft);
        break;
    case 2:
        tableFormat.setAlignment(Qt::AlignRight);
        break;
    default:
        break;
    }
    tableFormat.setBorderStyle( QTextTableFormat::BorderStyle_Solid );
    tableFormat.setCellPadding( 4 );
    tableFormat.setCellSpacing( 0 );
    tableFormat.setWidth( QTextLength( QTextLength::PercentageLength, 50 ) );

    fileManager->getCurrentTextEdit()->textCursor().insertTable(tableDialog->getRows(), tableDialog->getColumns(), tableFormat);

    QTextCursor cursor(fileManager->getCurrentTextEdit()->textCursor());
    cursor.setPosition(1);
    fileManager->getCurrentTextEdit()->setTextCursor(cursor);
    fileManager->getCurrentTextEdit()->textCursor().currentTable();
}

void MainWindow::on_action_17_triggered() // font selection
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        fileManager->getCurrentTextEdit()->setFont(font);
    }
}

void MainWindow::on_action_18_triggered() // select text color
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        QTextCursor cursor = fileManager->getCurrentTextEdit()->textCursor();
        cursor.mergeCharFormat(format);
        fileManager->getCurrentTextEdit()->mergeCurrentCharFormat(format);
    }
}

void MainWindow::on_action_15_triggered()
{
    this->editor->clearContent();
}

void MainWindow::on_action_7_triggered()
{
    this->editor->restoreContent();
}
