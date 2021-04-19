#include <gtest/gtest.h>
#include <tolerance.hxx>
#include <colour.hxx>

TEST(Colour, ColourCreate)
{
    Colour testClr;
    EXPECT_FLOAT_EQ(testClr[3], 0.0f);
}

TEST(Colour, Clamp)
{
    Colour testClr(3.0f, -2.0f, 1.0f);
    testClr.Clamp();

    EXPECT_TRUE(testClr == Colour(1.0f, 0.0f, 1.0f));
}

TEST(Colour, ClampNoChange)
{
    Colour testClr(0.2f, 0.3f, 1.0f);
    testClr.Clamp();

    EXPECT_TRUE(testClr == Colour(0.2f, 0.3f, 1.0f));
}

TEST(Colour, HadamardProduct)
{
    Colour c1(1.0f, 0.2f, 0.4f);
    Colour c2(0.9f, 1.0f, 0.1f);
    Colour c3 = (c1 * c2);

    EXPECT_TRUE(c3 == Colour(0.9f, 0.2f, 0.04f));
}