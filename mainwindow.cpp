#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidget(&m_label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mySlot()
{
    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "C:/Users/hp/Documents/Movavi/Test5/build",
                                                        tr("Images (*.png *.jpg)"));

        PyramidPicture pic(fileName);
        int k = ui->comboBox->currentIndex();
        //ui->label->setPixmap(QPixmap::fromImage(pic.getLayer(k)));
        //ui->label->setPixmap(QPixmap::fromImage(pic.getLayer(k)));
        m_label.setPixmap(QPixmap::fromImage(pic.getLayer(k)));

}
