#ifndef _COLOUR_HXX_
#define _COLOUR_HXX_

#include <tuple4.hxx>
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

    friend std::ostream& operator<<(std::ostream& os, const Colour& colour);

    Colour &Clamp();
};

using ColourVector = std::vector<Colour>;

#endif