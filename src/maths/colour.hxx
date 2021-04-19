#ifndef _COLOUR_HXX_
#define _COLOUR_HXX_

#include <private/tuple4.hxx>
#include <vector>

class Colour : public Tuple4
{
public:
    Colour();
    ~Colour();

    Colour(const Tuple4 &other);

    Colour &operator=(const Tuple4 &other);
};

using ColourVector = std::vector<Colour>;

#endif