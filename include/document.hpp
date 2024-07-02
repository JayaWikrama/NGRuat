#ifndef __DOCUMENT_HPP__
#define __DOCUMENT_HPP__

#include <ctime>
#include <string>

class Document {
  private:
    int fontSize;
    std::string headingFontColor;
    std::string headingFontFamily;
    std::string bodyFontColor;
    std::string bodyFontFamily;
    std::string title;
    std::string body;

  public:
    typedef enum _TEXT_TYPE_t {
      HEADING_1 = 0,
      HEADING_2,
      HEADING_3,
      HEADING_4,
      BODY
    } TEXT_TYPE_t;
    /**
     * @brief Default constructor.
     *
     * Berfungsi untuk melakukan setup waktu dan pawukon ke waktu saat object dibuat.
     */
    Document();

    /**
     * @brief Destructor.
     *
     * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
     */
    ~Document();

    /**
     * @brief Setter untuk Title Dokumen.
     *
     * Berfungsi untuk melakukan setup Title dokumen yang dilampirkan pada header file.
     * @param title dalam bentuk epoch timestamp.
     */
    void setTitle(const std::string title);

    /**
     * @brief Setter untuk konfigurasi style Headings.
     *
     * Berfungsi untuk melakukan setup style heading dokumen yang meliputi Font Family dan Font Color.
     * @param fontFamily Font Family.
     * @param fontColor warna text/huruf.
     */
    void setHeadingStyle(const std::string fontFamily, const std::string fontColor);

    /**
     * @brief Setter untuk konfigurasi style Body atau Text yang terdapat pada dokumen.
     *
     * Berfungsi untuk melakukan setup style text di dalam dokumen yang meliputi Font Family, Font Color, dan Font Size.
     * @param fontFamily Font Family.
     * @param fontColor warna text/huruf.
     * @param fontSz ukuran huruf (dalam pt).
     */
    void setBodyStyle(const std::string fontFamily, const std::string fontColor, unsigned short int fontSz);

    /**
     * @brief Menambah baris baru ke dokumen sesuai dengan type baris baru yang dimasukkan.
     *
     * Berfungsi untuk Menambah baris baru ke dokumen sesuai dengan type baris baru yang dimasukkan.
     * @param lineType type baris baru.
     * @param text konten baris baru yang akan ditambahkan.
     */
    void addLine(Document::TEXT_TYPE_t lineType, const std::string text);

    /**
     * @brief Getter untuk keseluruhan isi dari dokumen.
     *
     * Berfungsi untuk mengambil keseluruhan isi dokumen yang telah disusun.
     * @return keseluruhan isi dokumen yang telah disusun.
     */
    std::string getPayload();

    /**
     * @brief Document Writer.
     *
     * Berfungsi untuk menulis keseluruhan isi dokumen yang telah disusun kedalam sebuah file.
     * @param fileName nama file
     * @return 0 jika sukses.
     */
    int writeDocument(std::string fileName);
};

#endif