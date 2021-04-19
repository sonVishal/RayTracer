#include <tuple4.hxx>
#include <tolerance.hxx>

// Constructors
Tuple4::Tuple4()
{
    (*this)[0] = (*this)[1] = (*this)[2] = (*this)[3] = 0.0f;
}

Tuple4::Tuple4(float x, float y, float z, float w)
{
    (*this)[0] = x;
    (*this)[1] = y;
    (*this)[2] = z;
    (*this)[3] = w;
}

Tuple4::Tuple4(const Tuple4 &other)
{
    for (int i = 0; i < 4; ++i)
        (*this)[i] = other[i];
}

// Assignment operator
Tuple4 &Tuple4::operator=(const Tuple4 &other)
{
    for (int i = 0; i < 4; ++i)
        (*this)[i] = other[i];
    return *this;
}

// Indexing operators
float &Tuple4::operator[](int idx)
{
    if (idx < 4 && idx >= 0)
    {
        return m_elems[idx];
    }
    else
    {
        throw std::out_of_range("Received invalid index.");
    }
}

float Tuple4::operator[](int idx) const
{
    if (idx < 4 && idx >= 0)
    {
        return m_elems[idx];
    }
    else
    {
        throw std::out_of_range("Received invalid index.");
    }
}

// Math operators
Tuple4 Tuple4::operator+(const Tuple4 &other) const
{
    Tuple4 result;
    for (int i = 0; i < 4; ++i)
        result[i] = (*this)[i] + other[i];
    return result;
}

Tuple4 Tuple4::operator-(const Tuple4 &other) const
{
    Tuple4 result;
    for (int i = 0; i < 4; ++i)
        result[i] = (*this)[i] - other[i];
    return result;
}

Tuple4 Tuple4::operator-() const
{
    Tuple4 result(*this);
    for (int i = 0; i < 3; ++i)
        result[i] *= -1.0f;
    return result;
}

bool Tuple4::operator==(const Tuple4 &other) const
{
    bool isEq = true;
    for (int i = 0; i < 4; i++)
    {
        if (!IsEq((*this)[i], other[i]))
        {
            isEq = false;
            break;
        }
    }

    return isEq;
}

bool Tuple4::operator!=(const Tuple4 &other) const
{
    return !((*this) == other);
}

Tuple4 Tuple4::operator*(float val) const
{
    Tuple4 result;
    for (int i = 0; i < 3; i++)
        result[i] = (*this)[i] * val;
    return result;
}

Tuple4 Tuple4::operator/(float val) const
{
    if (IsEq(val, 0.0))
    {
        throw std::overflow_error("Division by Zero!!!!!");
    }
    Tuple4 result;
    for (int i = 0; i < 3; i++)
        result[i] = (*this)[i] / val;
    return result;
}

Tuple4 &Tuple4::operator*=(float val)
{
    (*this) = ((*this) * val);
    return (*this);
}

Tuple4 &Tuple4::operator/=(float val)
{
    (*this) = ((*this) / val);
    return (*this);
}