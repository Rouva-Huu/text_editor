#ifndef Editor_H
#define Editor_H

#include <declarations.h>
#include "filemanager.h"

class Editor
{
public:
    Editor(FileManager *&fileManager);
    void clearContent();
    void restoreContent();

private:
    static QTemporaryFile tempFile;
    FileManager *fileManager;
};

#endif // Editor_H
