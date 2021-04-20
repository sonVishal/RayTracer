#ifndef _PPM_WRITER_HXX_
#define _PPM_WRITER_HXX_

#include <private/imageWriterBase.hxx>

class PpmWriter : public ImageWriterBase
{
private:
    PpmWriter();

public:
    PpmWriter(Canvas *canvas, const std::string &fileName);
    void WriteData(size_t flush = 0) override;
    ~PpmWriter();
};

#endif