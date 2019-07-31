#include "pyramidpicture.h"
#include <QImageReader>
#include <QMessageBox>
#include <cmath>

PyramidPicture::PyramidPicture(const QString& name):
    m_name(name)
{
    QImageReader reader(m_name);

    m_pic = reader.read();

    m_height = m_pic.height();
    m_width  = m_pic.width();
    m_diag = m_height*m_height + m_width*m_width;
}

QImage PyramidPicture::getLayer(int k, double coef) const
{
    if (k == 0)
        return m_pic;

    double actualCoef = 1;

    for (int i = 0; i < k; i++)
        actualCoef *= coef;


    int height =  static_cast<int>( static_cast<double>(m_height) / actualCoef);
    int width =   static_cast<int>( static_cast<double>(m_width)  / actualCoef);

    QImage output(width, height, m_pic.format());

    for(int x = 0; x < width; x++)
            for(int y = 0; y < height; y++)
                output.setPixelColor(x, y, findColor(x, y, actualCoef));

    return output.scaled(m_width, m_height);

}

int PyramidPicture::getLayerCount(double coef) const
{
    double side = std::min(m_width, m_height);
    double outputD = std::log(side)/std::log(coef);
    int output = static_cast<int>(outputD) + 1;
    return output;
}


QColor PyramidPicture::findColor(int x, int y, double coef) const
{
    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;

    int xStart = static_cast<int>( static_cast<double>(x)*coef);
    int xEnd   = static_cast<int>( static_cast<double>(x + 1)*coef);
    int yStart = static_cast<int>( static_cast<double>(y)*coef);
    int yEnd   = static_cast<int>( static_cast<double>(y + 1)*coef);

    int count = (xEnd - xStart) * (yEnd - yStart);

    for (int i = xStart; i < xEnd; i++) {
        for (int j = yStart; j < yEnd; j++) {
            QColor color = m_pic.pixelColor(i, j);
            r += color.red();
            g += color.green();
            b += color.blue();
            a += color.alpha();
        }
    }

    r /= count;
    g /= count;
    b /= count;
    a /= count;
    return QColor(r, g, b, a);
}

