#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHash>
#include "pyramidpicture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void loadFile();

    // print actual layer of actual pictures to m_label
    void printLayer();

    void selectFile();

private:

    // add file to nameBox
    void addFile(const QString& filename);
    // find layers count for current file and coef
    void updateLayersBox(const PyramidPicture& pic);


    Ui::MainWindow *ui;
    QLabel m_label;
    QHash<QString, PyramidPicture> m_pictures;
};

#endif // MAINWINDOW_H
