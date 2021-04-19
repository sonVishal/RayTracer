#ifndef _TUPLE4_HXX_
#define _TUPLE4_HXX_

#include <stdexcept>
#include <gtest/gtest_prod.h>

class Tuple4Factory;

class Tuple4
{
private:
    float m_elems[4];

protected:
    Tuple4();

public:
    virtual ~Tuple4() {}

    // Copy constructor
    Tuple4(const Tuple4 &other);

    // Assignment operator
    Tuple4 &operator=(const Tuple4 &other);

    // Indexing operators
    float &operator[](int idx);
    float operator[](int idx) const;

    // Math operators
    Tuple4 operator+(const Tuple4 &other) const;
    Tuple4 operator-(const Tuple4 &other) const;
    Tuple4 operator-() const;
    bool operator==(const Tuple4 &other) const;
    Tuple4 operator*(float val) const;
    Tuple4 operator/(float val) const;

    Tuple4 &operator*=(float val);
    Tuple4 &operator/=(float val);
};

#endif