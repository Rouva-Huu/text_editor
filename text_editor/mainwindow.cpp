#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"

FileManager *fileManager;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileManager = new FileManager(ui->tabWidget, NULL);
}

MainWindow::~MainWindow()
{
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
    // QTextTableFormat tableFormat;
    // tableFormat.setAlignment(Qt::AlignCenter);
    // tableFormat.setBorderStyle( QTextTableFormat::BorderStyle_Solid );
    // tableFormat.setCellPadding( 4 );
    // tableFormat.setCellSpacing( 0 );
    // tableFormat.setWidth( QTextLength( QTextLength::PercentageLength, 50 ) );

    // ui->textEdit->textCursor().insertTable(3, 7, tableFormat);

    // QTextCursor cursor(ui->textEdit->textCursor());
    // cursor.setPosition(1);
    // ui->textEdit->setTextCursor(cursor);

    // ui->textEdit->textCursor().currentTable();
}

void MainWindow::on_action_17_triggered() // font selection
{
    // bool ok;
    // QFont font = QFontDialog::getFont(&ok, this);
    // if (ok) {
    //     ui->textEdit->setFont(font);
    // }
}

void MainWindow::on_action_18_triggered() // select text color
{
    // QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    // if (color.isValid()) {
    //     QTextCharFormat format;
    //     format.setForeground(color);
    //     QTextCursor cursor = ui->textEdit->textCursor();
    //     cursor.mergeCharFormat(format);
    //     ui->textEdit->mergeCurrentCharFormat(format);
    // }
}
