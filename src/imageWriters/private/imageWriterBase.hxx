#ifndef _IMAGE_WRITER_BASE_HXX_
#define _IMAGE_WRITER_BASE_HXX_

#include <string>
#include <fstream>
#include <canvas.hxx>

class ImageWriterBase
{
public:
    enum class FileType
    {
        Ascii,
        Binary
    };

private:
    Canvas *m_canvas{};
    std::string m_extension{};
    std::string m_fileName{};
    std::string m_header{};
    std::string m_footer{};
    std::ofstream m_file{};
    FileType m_fileType{};

protected:
    ImageWriterBase();
    ImageWriterBase(Canvas *canvas, const std::string &fileName, const std::string &extension, FileType m_fileType);
    void SetHeader(const std::string &header);
    void SetFooter(const std::string &footer);
    void WriteData(const std::string &data);
    void WriteHeader();
    void WriteFooter();
    Canvas *GetCanvas() const { return m_canvas; }

public:
    virtual ~ImageWriterBase();
    virtual void WriteData(size_t flushSize = 0) = 0;
};

#endif