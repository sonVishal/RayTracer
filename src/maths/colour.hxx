#ifndef _COLOUR_HXX_
#define _COLOUR_HXX_

#include <private/tuple4.hxx>
#include <vector>

class Colour : public Tuple4
{
public:
    Colour();
    ~Colour();
    Colour(float r, float g, float b);

    Colour(const Tuple4 &other);

    Colour &operator=(const Tuple4 &other);

    Colour operator*(const Colour &other) const;

    Colour &Clamp();
};

using ColourVector = std::vector<Colour>;

#endif