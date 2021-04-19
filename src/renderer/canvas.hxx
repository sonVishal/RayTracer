#ifndef _CANVAS_HXX_
#define _CANVAS_HXX_

#include <colour.hxx>

class Canvas
{
private:
    ColourVector m_pixels;
    int m_width, m_height;
public:
    Canvas(/* args */);
    ~Canvas();
};

#endif