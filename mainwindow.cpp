#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

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

void MainWindow::loadFile()
{
    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "C:/",
                                                        tr("Images (*.png *.jpg)"));

        addFile(filename);
}

void MainWindow::addFile(const QString& filename)
{
    if (m_pictures.count(filename))
    {
        QMessageBox::information(0, "Error", "File '" + filename + "' is already loaded");
        return;
    }

    PyramidPicture pic(filename);
    int diag = pic.getDiagonal();
    // put new file name to ui->nameBox
    int i = 0;
    int n = ui->nameBox->count();

    for (; i < n; i++)
    {
        QString anotherFilename = ui->nameBox->itemText(i);
        if (diag < m_pictures.find(anotherFilename).value().getDiagonal())
            break;
    }
    m_pictures.insert(filename, pic);
    ui->nameBox->insertItem(i, filename);
    ui->nameBox->setCurrentIndex(i);
}

void MainWindow::printLayer()
{
    if (!ui->nameBox->count())
        return;
    if (!m_pictures.count(ui->nameBox->currentText()))
    {
        QMessageBox::information(0, "Error", "File '" + ui->nameBox->currentText() + "' not loaded");
        return;
    }

    PyramidPicture& pic = m_pictures.find(ui->nameBox->currentText()).value();
    int layerNumber = ui->layerBox->currentIndex();
    double coef = ui->coefBox->value();

    Layer layer = pic.getLayer(layerNumber, coef);

    m_label.setPixmap(QPixmap::fromImage(layer.m_LayerImage));
    ui->sizelabel->setText("Size: " + QString::number(layer.m_width) + "x" + QString::number(layer.m_height));
}

void MainWindow::selectFile()
{
    if (!m_pictures.count(ui->nameBox->currentText()))
    {
        QMessageBox::information(0, "Error", "File '" + ui->nameBox->currentText() + "' not loaded");
        return;
    }
    updateLayersBox(m_pictures.find(ui->nameBox->currentText()).value());
}

void MainWindow::updateLayersBox(const PyramidPicture& pic)
{
    int countLayers = pic.getLayerCount(ui->coefBox->value());
    ui->layerBox->clear();
    for(int i = 0; i < countLayers; i++)
       ui->layerBox->insertItem(i, QString::number(i));
    ui->layerBox->setCurrentIndex(0);
}
