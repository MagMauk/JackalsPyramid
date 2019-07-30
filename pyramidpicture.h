#ifndef PYRAMIDPICTURE_H
#define PYRAMIDPICTURE_H

#include <QImage>
#include <QVector>


class PyramidPicture
{
public:
    PyramidPicture();

private:
    QColor findColor(int i, int x, int y);

private:

    int size;
    int dim;
    QString m_name;
    QVector<QImage> m_pictures;
};

#endif // PYRAMIDPICTURE_H
