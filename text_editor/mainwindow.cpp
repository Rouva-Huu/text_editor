#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "declarations.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered() // creating a new file
{
}

void MainWindow::on_action_2_triggered() // open existing file
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"),
                                                    QDir::currentPath(),
                                                    "Text Files (*.txt);;All Files (*.*)");
    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    QTextStream in(&file);
    QString fileContent = in.readAll();

    QTextEdit *textEdit = new QTextEdit;
    textEdit->setText(fileContent);



    QFileInfo fileInfo(filePath);
    QString fileNameWithoutExtension = fileInfo.completeBaseName();
    ui->tabWidget->addTab(textEdit, fileNameWithoutExtension);

    file.flush();
}

void MainWindow::on_action_4_triggered() // save to existing path
{

}

void MainWindow::on_action_5_triggered() // save to specified path
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"),
                                                    QDir::currentPath(),
                                                    "Text Files (*.txt);;All Files (*.*)");
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
