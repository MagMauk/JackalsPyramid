#ifndef PYRAMIDPICTURE_H
#define PYRAMIDPICTURE_H

#include <QImage>
#include <QVector>


class PyramidPicture
{
public:
    PyramidPicture(const QString& name);

    QImage getLayer(int k, double coef = 2) const;

    int getDiagonal() const
    {
        return m_diag;
    }

    int getHeight()
    {
        return m_height;
    }

    int getWidth()
    {
        return m_width;
    }

private:
    QColor findColor(int i, int x, int y) const;

    QColor findColor(int x, int y, double coef) const;

    void makePyramideStep();

private:

    QString m_name;
    QImage m_pic;
    int m_height, m_width, m_diag;
};

#endif // PYRAMIDPICTURE_H
