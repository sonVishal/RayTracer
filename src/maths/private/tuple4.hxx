#ifndef _TUPLE4_HXX_
#define _TUPLE4_HXX_

#include <stdexcept>

class Tuple4
{
private:
    float elems[4];

protected:
    Tuple4();
    void SetPerspectiveTerm(float w)
    {
        elems[3] = w;
    }

public:
    virtual ~Tuple4();

    void Set(float val[3])
    {
        for (int i = 0; i < 3; i++)
        {
            elems[i] = val[i];
        }
    }

    void Set(float x, float y, float z)
    {
        elems[0] = x;
        elems[1] = y;
        elems[2] = z;
    }

    float operator[](int idx)
    {
        if (idx < 4)
        {
            return elems[idx];
        }
        else
        {
            throw std::out_of_range("Received invalid index.");
        }
    }
};

#endif