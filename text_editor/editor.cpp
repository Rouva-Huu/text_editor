#include "editor.h"

QTemporaryFile Editor::tempFile;

Editor::Editor(FileManager *&fileManager)
{
    this->fileManager = fileManager;
}

void Editor::clearContent() {
    if (!this->tempFile.isOpen()) {
        if (!this->tempFile.open())
            return; // Открываем временный файл
    }

    // Сохраняем текущее содержимое
    QString currentContent = fileManager->getCurrentTextEdit()->toPlainText();
    this->tempFile.write(currentContent.toUtf8());
    this->tempFile.flush();
    this->tempFile.close(); // Закрываем временный файл

    // Очищаем текстовое поле
    fileManager->getCurrentTextEdit()->clear();
}

// Восстановление содержимого
void Editor::restoreContent() {
    if (this->tempFile.exists()) {
        if (this->tempFile.open())
        { // Открываем временный файл для чтения
            QString savedContent = QString::fromUtf8(this->tempFile.readAll());
            fileManager->getCurrentTextEdit()->setPlainText(savedContent);
            this->tempFile.close(); // Закрываем временный файл
        }
    }
}
