#include <colour.hxx>

Colour::Colour()
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

Colour::~Colour()
{
}