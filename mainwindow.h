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
    void mySlot();

    void printLayer();

private:

    void addFile(const QString& filename);

    void updateLayersBox(const PyramidPicture& pic);

    Ui::MainWindow *ui;
    QLabel m_label;
    // QHash haven't the analog of method std::unordered_map::at
    QHash<QString, PyramidPicture> m_pictures;
};

#endif // MAINWINDOW_H
