#ifndef _TUPLE4_HXX_
#define _TUPLE4_HXX_

#include <stdexcept>
#include <gtest/gtest_prod.h>

class Tuple4
{
private:
    float m_elems[4];

protected:
    Tuple4();
    void SetPerspectiveTerm(float w)
    {
        m_elems[3] = w;
    }

public:
    virtual ~Tuple4() {}

    float GetPerspectiveTerm() const
    {
        return m_elems[3];
    }

    void Set(float val[3])
    {
        for (int i = 0; i < 3; i++)
        {
            m_elems[i] = val[i];
        }
    }

    

    void Set(float x, float y, float z)
    {
        m_elems[0] = x;
        m_elems[1] = y;
        m_elems[2] = z;
    }

    float operator[](int idx) const
    {
        if (idx < 4)
        {
            return m_elems[idx];
        }
        else
        {
            throw std::out_of_range("Received invalid index.");
        }
    }
};

#endif