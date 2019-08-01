#ifndef PYRAMIDPICTURE_H
#define PYRAMIDPICTURE_H

#include <QImage>
#include <QVector>

struct Layer{
    QImage m_LayerImage;
    int m_width, m_height;

    Layer(QImage image, int width, int heigth):
        m_LayerImage (image),
        m_width (width),
        m_height (heigth) {}
};

class PyramidPicture
{
public:
    PyramidPicture(const QString& name);

    // method return the k layer of m_pic with coefficent coef
    Layer getLayer(int k, double coef = 2) const;

    // method return the size pyramid of m_pic with coefficent coef
    int getLayerCount(double coef = 2) const;

    int getDiagonal() const
    {
        return m_diag;
    }

    int getWidth()
    {
        return m_width;
    }

    int getHeight()
    {
        return m_height;
    }

private:
    QColor findColor(int i, int x, int y) const;

    QColor findColor(int x, int y, double coef) const;

    void makePyramideStep();

private:

    QString m_name;
    QImage m_pic;
    int m_width, m_height, m_diag;
};

#endif // PYRAMIDPICTURE_H
