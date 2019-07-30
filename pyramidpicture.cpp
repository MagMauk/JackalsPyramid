#include "pyramidpicture.h"

PyramidPicture::PyramidPicture()
{

}

QColor PyramidPicture::findColor(int k, int x, int y)
{
   int r = 0;
   int g = 0;
   int b = 0;
   int a = 0;

   int prevX = x * dim;
   int prevY = y * dim;

   for (int i = 0; i < dim; i++)
       for (int j = 0; j < dim; j++) {
           QColor color = m_pictures[k].pixelColor(prevX + i, prevY + j);
           r += color.red();
           g += color.green();
           b += color.blue();
           a += color.alpha();
       }

   r /= dim*dim;
   g /= dim*dim;
   b /= dim*dim;
   a /= dim*dim;
   return QColor(r, g, b, a);
}
