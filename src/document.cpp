#include <iostream>
#include <string>
#include <fstream>
#include "document.hpp"

/**
 * @brief Default constructor.
 * fontSize = 12
 * headingColor = "#555555"
 * headingFontFamily = "Arial, sans-serif"
 * bodyFontColor = "#000000"
 * bodyFontFamily = "Arial, sans-serif"
 * title = "New Document"
 * Berfungsi untuk melakukan setup parameter ke nilai default.
 * 
 */
Document::Document(){
  this->docType = static_cast<unsigned int>(Document::PLAIN_TEXT);
  this->fontSize = 12;
  this->headingFontColor = "#555555";
  this->headingFontFamily = "Arial, sans-serif";
  this->bodyFontColor = "#000000";
  this->bodyFontFamily = "Arial, sans-serif";
  this->title = "New Document";
}

/**
 * @brief Destructor.
 *
 * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
 */
Document::~Document(){

}

/**
 * @brief Setter untuk Tipe Dokumen yang akan dibangun.
 *
 * Berfungsi untuk melakukan setup tipe dokumen yang akan dibuat. Method ini dapat dipanggil sebelum memangil method __Document::getPayload__ atau __Document::writeDocument__.
 * @param type merepresentasikan jenis dokumen yang akan dibuat.
 */
void Document::setDocumentType(Document::DOCUMENT_TYPE_t type){
  this->docType = static_cast<unsigned int>(type);
}

/**
 * @brief Setter untuk Title Dokumen.
 *
 * Berfungsi untuk melakukan setup Title dokumen yang dilampirkan pada header file.
 * @param title dalam bentuk epoch timestamp.
 */
void Document::setTitle(const std::string title){
  this->title = title;
}

/**
 * @brief Setter untuk konfigurasi style Headings.
 *
 * Berfungsi untuk melakukan setup style heading dokumen yang meliputi Font Family dan Font Color.
 * @param fontFamily Font Family.
 * @param fontColor warna text/huruf.
 */
void Document::setHeadingStyle(const std::string fontFamily, const std::string fontColor){
  this->headingFontFamily = fontFamily;
  this->headingFontColor = fontColor;
}

/**
 * @brief Setter untuk konfigurasi style Body atau Text yang terdapat pada dokumen.
 *
 * Berfungsi untuk melakukan setup style text di dalam dokumen yang meliputi Font Family, Font Color, dan Font Size.
 * @param fontFamily Font Family.
 * @param fontColor warna text/huruf.
 * @param fontSz ukuran huruf (dalam pt).
 */
void Document::setBodyStyle(const std::string fontFamily, const std::string fontColor, unsigned short int fontSz){
  this->bodyFontFamily = fontFamily;
  this->bodyFontColor = fontColor;
  this->fontSize = fontSz;
}

/**
 * @brief Menambah baris baru ke dokumen sesuai dengan type baris baru yang dimasukkan.
 *
 * Berfungsi untuk Menambah baris baru ke dokumen sesuai dengan type baris baru yang dimasukkan.
 * @param lineType type baris baru.
 * @param text konten baris baru yang akan ditambahkan.
 */
void Document::addLine(Document::TEXT_TYPE_t lineType, const std::string text){
  struct body_t line = {static_cast<unsigned int>(lineType), text};
  this->body.push_back(line);
}

/**
 * @brief Getter untuk keseluruhan isi dari dokumen.
 *
 * Berfungsi untuk mengambil keseluruhan isi dokumen yang telah disusun.
 * @return keseluruhan isi dokumen yang telah disusun.
 */
std::string Document::getPayload(){
  std::string body;
  for (auto i = this->body.begin(); i != this->body.end(); i++){
    if (static_cast<Document::DOCUMENT_TYPE_t>(this->docType) == Document::PLAIN_TEXT){
      body += (*i).text + "\n";
    }
    else if (static_cast<Document::DOCUMENT_TYPE_t>(this->docType) == Document::DOCUMENT){
      if (static_cast<Document::TEXT_TYPE_t>((*i).type) == BODY){
        body += "<p>" + (*i).text + "</p>";
      }
      else {
        body += "<h" + std::to_string((*i).type + 1) + ">" + (*i).text + "</h" + std::to_string((*i).type + 1) + ">";
      }
    }
    else {
      if (static_cast<Document::TEXT_TYPE_t>((*i).type) == BODY){
        body += (*i).text + "\n\n";
      }
      else {
        for (int j = 0; j <= (*i).type; j++){
          body += "#";
        }
        body += " " + (*i).text + "\n\n";
      }
    }
  }
  std::string result = std::string("<html>") +
                       std::string("<head>") +
                       std::string("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">") +
                       std::string("<title>") + this->title + std::string("</title>") +
                       std::string("<style>") +
                       std::string("h1, h2, h3, h4 {font-family:") +
                        this->headingFontFamily + std::string(";color:") +
                        this->headingFontColor + std::string(";}") +
                       std::string("p {font-family:") +
                        this->bodyFontFamily + std::string(";font-size:") +
                        std::to_string(this->fontSize) + std::string("pt;color:") +
                        this->bodyFontColor + std::string(";}") +
                       std::string("</style>") +
                       std::string("</head>") +
                       std::string("<body>\n") +
                       body +
                       std::string("\n</body>") +
                       std::string("</html>");

  return result;
}

/**
 * @brief Document Writer.
 *
 * Berfungsi untuk menulis keseluruhan isi dokumen yang telah disusun kedalam sebuah file.
 * @param fileName nama file
 * @return 0 jika sukses.
 */
int Document::writeDocument(std::string fileName){
  std::ofstream file(fileName);
  if (!file.is_open()) {
    return 1;
  }
  file  << this->getPayload() << std::endl;
  file.close();
  return 0;
}