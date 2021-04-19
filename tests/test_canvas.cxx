#include <gtest/gtest.h>
#include <canvas.hxx>
#include <colour.hxx>

TEST(Canvas, Create)
{
    Canvas testCanvas(5, 4);
    EXPECT_EQ(5, testCanvas.GetWidth());
    EXPECT_EQ(4, testCanvas.GetHeight());
    Colour zeroColour;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 4; ++j)
            EXPECT_TRUE(testCanvas.GetPixelAt(i, j) == zeroColour);
}

TEST(Canvas, WritePixelAt)
{
    Canvas testCanvas(5, 4);
    Colour red(1.0f, 0.0f, 0.0f);
    testCanvas.WritePixelAt(2, 3, red);
    EXPECT_TRUE(testCanvas.GetPixelAt(2, 3) == red);
}

TEST(Canvas, WriteAllPixels)
{
    Canvas testCanvas(5, 4);
    Colour red(1.0f, 0.0f, 0.0f);
    testCanvas.WritePixels(red);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 4; ++j)
            EXPECT_TRUE(testCanvas.GetPixelAt(i, j) == red);
}