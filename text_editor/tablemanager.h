#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QObject>
#include "declarations.h"
#include "tabledialog.h"

class TableManager : public QWidget
{
    Q_OBJECT

public:
    explicit TableManager(QTabWidget* tabWidget, QWidget* parent = nullptr);

public slots:
    void createNewTable(int rows, int columns);
    void openTable();
    void saveTable();
    void saveTableAs();
    void closeTab(int index);
    void setTextColor(QColor color);
    void setBackColor(QColor color);

    QTableWidget* getCurrentTable();

private:
    QTabWidget* m_tabWidget;
    QString m_currentFileName; // имя открытого файла

};

#endif // TABLEMANAGER_H
