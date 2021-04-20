#include <private/imageWriterBase.hxx>
#include <ios>
#include <iostream>

ImageWriterBase::ImageWriterBase()
{
}

ImageWriterBase::ImageWriterBase(Canvas *canvas, const std::string &fileName, const std::string &extension,
                                 ImageWriterBase::FileType fileType) : m_canvas(canvas), m_fileName{fileName},
                                                                       m_extension(extension), m_fileType(fileType)
{
    m_fileName += m_extension;
    m_file.open(m_fileName.c_str(), std::ofstream::trunc | std::ofstream::out);
    m_file.close();
}

void ImageWriterBase::WriteHeader()
{
    m_file.open(m_fileName.c_str(), std::ofstream::app);
    m_file << m_header;
    m_file.close();
}

void ImageWriterBase::WriteFooter()
{
    m_file.open(m_fileName.c_str(), std::ofstream::app);
    m_file << m_footer;
    m_file.close();
}

void ImageWriterBase::WriteData(const std::string &data)
{
    m_file.open(m_fileName.c_str(), std::ofstream::app);
    m_file << data;
    m_file.close();
}

void ImageWriterBase::SetHeader(const std::string &header)
{
    m_header.assign(header);
}

void ImageWriterBase::SetFooter(const std::string &footer)
{
    m_footer.assign(footer);
}

ImageWriterBase::~ImageWriterBase()
{
    m_file.close();
}