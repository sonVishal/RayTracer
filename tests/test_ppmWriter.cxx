#include <gtest/gtest.h>
#include <canvas.hxx>
#include <colour.hxx>
#include <ppmWriter.hxx>
#include <fstream>
#include <iterator>

TEST(PpmWriter, WriteFile)
{
    {
        Canvas canvas(5, 3);
        canvas.WritePixelAt(1, 2, Colour(1.0f, 0.0f, 0.0f));
        canvas.WritePixelAt(2, 1, Colour(0.0f, 1.0f, 0.0f));
        canvas.WritePixelAt(4, 2, Colour(0.0f, 0.0f, 1.0f));
        PpmWriter ppmWriter(&canvas, "./test");
        ppmWriter.WriteData();
    }

    std::ifstream writtenFile;
    writtenFile.open("./test.ppm");
    std::string line;
    std::string contents;
    int nLines = 0;
    while (std::getline(writtenFile, line))
    {
        line += "\n";
        contents += line;
        nLines++;
        line.clear();
    }
    writtenFile.close();

    EXPECT_TRUE(nLines == 7);
    const std::string actualOutput("P3\n5 3\n255\n0 0 0 255 0 0 0 0 0 0 0 0 0 0 255 \n0 0 0 0 0 0 0 255 0 0 0 0 0 0 0 \n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \n\n");
    EXPECT_TRUE(contents == actualOutput);
}