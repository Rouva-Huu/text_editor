#include "tabledialog.h"
#include "ui_tabledialog.h"

TableDialog::TableDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TableDialog)
{
    ui->setupUi(this);
}

TableDialog::~TableDialog()
{
    delete ui;
}

int TableDialog::getColumns() {
    return ui->spinBox->value();
}

int TableDialog::getRows() {
    return ui->spinBox_2->value();
}

