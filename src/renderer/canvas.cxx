#include <canvas.hxx>

Canvas::Canvas()
{
}

Canvas::Canvas(int w, int h) : m_width(w), m_height(h)
{
    m_pixels = new Colour[w * h]{Colour()};
}

void Canvas::WritePixelAt(int x, int y, const Colour &colour)
{
    m_pixels[x + y * m_width] = colour;
}

Colour Canvas::GetPixelAt(int x, int y)
{
    return m_pixels[x + y * m_width];
}

int Canvas::GetWidth() const
{
    return m_width;
}

int Canvas::GetHeight() const
{
    return m_height;
}

void Canvas::WritePixels(const Colour &colour)
{
    int numPixels = m_width * m_height;
    for (int i = 0; i < numPixels; ++i)
        m_pixels[i] = colour;
}

Canvas::~Canvas()
{
    delete[] m_pixels;
}