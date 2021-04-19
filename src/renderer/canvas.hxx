#ifndef _CANVAS_HXX_
#define _CANVAS_HXX_

#include <colour.hxx>

class Canvas
{
private:
    Colour *m_pixels{nullptr};
    int m_width{0}, m_height{0};
    Canvas();

public:
    Canvas(int w, int h);
    ~Canvas();

    int GetWidth() const;
    int GetHeight() const;
    void WritePixelAt(int x, int y, const Colour &colour);
    void WritePixels(const Colour &colour);
    Colour GetPixelAt(int x, int y);
};

#endif