#include "tablemanager.h"

TableManager::TableManager(QTabWidget* tabWidget, QWidget* parent)
    : QWidget(parent), m_tabWidget(tabWidget) {
    connect(m_tabWidget, &QTabWidget::tabCloseRequested, this, &TableManager::closeTab);
}

void TableManager::createNewTable(int rows, int columns)
{
    QTableWidget* table = new QTableWidget(rows, columns);
    QString tabName = "Новая таблица";
    m_tabWidget->addTab(table, tabName);
    m_tabWidget->setCurrentWidget(table);
    m_currentFileName.clear();
}

void TableManager::openTable()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("CSV files (*.csv);;All Files (*)"));
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Не удалось открыть CSV файл"));
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    int rows = lines.size();
    int columns = !lines.isEmpty() ? lines.first().split(";").size() : 0;

    if (rows == 0 || columns == 0) {
        QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Файл CSV пуст или имеет неправильный формат"));
        return;
    }

    QTableWidget* tableWidget = new QTableWidget(rows, columns);
    if (!tableWidget) {
        QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Не удалось создать таблицу"));
        return;
    }

    for (int i = 0; i < rows; ++i) {
        QStringList cells = lines.at(i).split(";");
        if (cells.size() != columns) {
            QMessageBox::warning(nullptr, QObject::tr("Ошибка"), QObject::tr("Некорректный CSV файл: строки содержат разное количество столбцов"));
            delete tableWidget;
            return;
        }

        for (int j = 0; j < cells.size(); ++j) {
            tableWidget->setItem(i, j, new QTableWidgetItem(cells.at(j)));
        }
    }

    QString tabName = QFileInfo(fileName).fileName();
    m_tabWidget->addTab(tableWidget, tabName);
    m_tabWidget->setCurrentWidget(tableWidget);
    m_currentFileName = fileName;

}

void TableManager::saveTable()
{
    if (m_tabWidget->count() == 0) {
        return;
    }

    if (m_currentFileName.isEmpty()) {
        saveTableAs();
        return;
    }

    QTableWidget* currentTable = qobject_cast<QTableWidget*>(m_tabWidget->currentWidget());
    if (currentTable) {
        QFile file(m_currentFileName);
        QAbstractItemModel *model =  getCurrentTable()->model();
        if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сохранить файл"));
            return;
        }
        else
        {
            QTextStream data(&file);
            QStringList strList;
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append(model->data(model->index(i, j)).toString());
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
        }
    }

    int currentIndex = m_tabWidget->currentIndex();
    if (currentIndex != -1) {
        QString newTabName = QFileInfo(m_currentFileName).baseName();
        m_tabWidget->setTabText(currentIndex, newTabName);
    }
}

void TableManager::saveTableAs()
{
    if (m_tabWidget->count() == 0) {
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), "", tr("CSV files (*.csv);;All Files (*)"));
    if (fileName.isEmpty()) return;

    m_currentFileName = fileName;
    saveTable();
}

void TableManager::closeTab(int index)
{
    if (index >= 0) {
        m_tabWidget->removeTab(index);
    }
}

QTableWidget* TableManager::getCurrentTable()
{
    QTableWidget *table = qobject_cast<QTableWidget *>(m_tabWidget->currentWidget());
    return table;
}

void TableManager::setTextColor(QColor color)
{

    QList<QTableWidgetItem*> selectedItems = getCurrentTable()->selectedItems();
    for (QTableWidgetItem *item : selectedItems) {
        item->setForeground(color);
    }
}

void TableManager::setBackColor(QColor color)
{
    QList<QTableWidgetItem*> selectedItems = getCurrentTable()->selectedItems();
    for (QTableWidgetItem *item : selectedItems) {
        item->setBackground(color);
    }
}
