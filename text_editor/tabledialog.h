#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <QDialog>

namespace Ui {
class TableDialog;
}

class TableDialog : public QDialog
{
    Q_OBJECT

public:
    int getColumns();
    int getRows();
    // int tableAlignment();
    explicit TableDialog(QWidget *parent = nullptr);
    ~TableDialog();

private:
    Ui::TableDialog *ui;
};

#endif // TABLEDIALOG_H
