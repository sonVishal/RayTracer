#include <colour.hxx>

Colour::Colour() : Tuple4()
{
}

Colour::Colour(float r, float g, float b) : Tuple4(r, g, b, 0.0f)
{
}

Colour::Colour(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
}

Colour &Colour::operator=(const Tuple4 &other)
{
    for (int i = 0; i < 3; ++i)
        (*this)[i] = other[i];
    return (*this);
}

Colour Colour::operator*(const Colour &other) const
{
    Colour result;
    for (int i = 0; i < 3; ++i)
        result[i] = (*this)[i] * other[i];
    return result;
}

Colour &Colour::Clamp()
{
    for (int i = 0; i < 4; i++)
    {
        if ((*this)[i] < 0.0)
            (*this)[i] = 0.0;
        else if ((*this)[i] > 1.0)
            (*this)[i] = 1.0;
    }
    return *this;
}

Colour Colour::operator*(float val) const
{
    Colour scaled = static_cast<Tuple4>(*this) * val;
    return scaled;
}

std::ostream &operator<<(std::ostream &os, const Colour &colour)
{
    os << int(255 * colour[0]) << ' ' << int(255 * colour[1]) << ' ' << int(255 * colour[2]);
    return os;
}

Colour::~Colour()
{
}