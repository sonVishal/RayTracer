#include <ppmWriter.hxx>
#include <sstream>

PpmWriter::PpmWriter()
{
}

PpmWriter::PpmWriter(Canvas *canvas,
                     const std::string &fileName) : ImageWriterBase(canvas, fileName, ".ppm",
                                                                    ImageWriterBase::FileType::Ascii)
{
    std::stringstream header;
    header << "P3\n"
         << this->GetCanvas()->GetWidth() << ' ';
    header << this->GetCanvas()->GetHeight() << '\n';
    header << 255 << '\n';
    SetHeader(header.str());

    std::stringstream footer;
    footer << '\n';
    SetFooter(footer.str());
}

void PpmWriter::WriteData(size_t flush)
{
    WriteHeader();
    const size_t nColoursPerLine = 5;
    int w = this->GetCanvas()->GetWidth();
    int h = this->GetCanvas()->GetHeight();
    int pixelCount = 0;
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = 0; j < w; j++)
        {
            std::stringstream str;
            str << this->GetCanvas()->GetPixelAt(j, i) << ' ';
            ImageWriterBase::WriteData(str.str());
            pixelCount++;
            if (pixelCount % nColoursPerLine == 0)
            {
                ImageWriterBase::WriteData("\n");
            }
        }
    }

    WriteFooter();
}

PpmWriter::~PpmWriter()
{
}