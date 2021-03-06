#ifndef _TUPLE4_HXX_
#define _TUPLE4_HXX_

#include <stdexcept>
#include <ostream>

class Tuple4Factory;

class Tuple4
{
private:
    float m_elems[4];

protected:
    Tuple4();
    Tuple4(float x, float y, float z, float w);

public:
    virtual ~Tuple4() {};

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
    bool operator!=(const Tuple4 &other) const;
    Tuple4 operator*(float val) const;
    Tuple4 operator/(float val) const;
    friend std::ostream& operator<<(std::ostream& os, const Tuple4& tuple);

    Tuple4 &operator*=(float val);
    Tuple4 &operator/=(float val);
};

#endif