#include <iostream>
#include <ctime>
#include <string>
#include <string.h>
#include "ruwatan.hpp"
#include "Balinese-Wariga/include/wariga.hpp"

#define RUWATAN_DATABASE_REF "./asset/database/ruwatan.db"

static const std::string pawukonStr[] = {
  "Sinta",
  "Landep",
  "Ukir",
  "Kulantir",
  "Tolu",
  "Gumbreg",
  "Wariga",
  "Warigadean",
  "Julungwangi",
  "Sungsang",
  "Dungulan",
  "Kuningan",
  "Langkir",
  "Medangsia",
  "Pujut",
  "Pahang",
  "Krulut",
  "Merakih",
  "Tambir",
  "Medangkungan",
  "Matal",
  "Uye",
  "Menail",
  "Prangbakat",
  "Bala",
  "Ugu",
  "Wayang",
  "Kelawu",
  "Dukut",
  "Watugunung",
  "Unknown"
};

static const std::string saptaWaraLabel[] = {
  "Redite",
  "Soma",
  "Anggara",
  "Budha",
  "Wraspati",
  "Sukra",
  "Saniscara",
  "Unknown"
};

/**
 * @brief Default constructor.
 *
 * Berfungsi untuk melakukan setup private data ke nilai default.
 */
Ruwatan::Ruwatan(){
  this->database = RUWATAN_DATABASE_REF;
  this->setDatabase(this->database);
}

/**
 * @brief Destructor.
 *
 * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
 */
Ruwatan::~Ruwatan(){
  
}

/**
 * @brief Setter untuk setup referensi database yang digunakan.
 *
 * Berfungsi untuk melakukan setup referensi database yang digunakan sebagai basis data.
 * Method ini wajib dipanggil sebelum memanggil method __Ruwatan::setup__ jika ingin menggunakan referensi database custom.
 * @param fileName nama file database (lengkap dengan directory path-nya).
 */
void Ruwatan::setDatabase(const std::string fileName){
  this->database = fileName;
  this->ekaWara.setDatabase(fileName);
  this->dwiWara.setDatabase(fileName);
  this->triWara.setDatabase(fileName);
  this->caturWara.setDatabase(fileName);
  this->pancaWara.setDatabase(fileName);
  this->sadWara.setDatabase(fileName);
  this->saptaWara.setDatabase(fileName);
  this->astaWara.setDatabase(fileName);
  this->sangaWara.setDatabase(fileName);
  this->dasaWara.setDatabase(fileName);
}

/**
 * @brief Setter untuk setup informasi nama dan data kelahiran orang yang akan diruat.
 *
 * Berfungsi untuk melakukan setup informasi nama dan data kelahiran orang yang akan diruat.
 * @param name diisi dengan nama orang yang akan diruat.
 * @param birthDate diisi dengan informasi waktu kelahiran orang yang akan di ruat. Contoh: disi dengan format YYYY-MM-DD (2000-04-21)
 * @return 0 jika sukses
 */
int Ruwatan::setup(const std::string name, const std::string birthDate){
  int ret = 0;
  Wariga wariga;
  ret = wariga.setup(birthDate);
  if (ret == 0){
    ret = this->setup(name, wariga.getPawukonStr(), wariga.saptaWara.getName());
  }
  else {
    ret += 70;
  }
  return ret;
}

/**
 * @brief Setter untuk setup informasi nama dan data kelahiran orang yang akan diruat.
 *
 * Berfungsi untuk melakukan setup informasi nama dan data kelahiran orang yang akan diruat.
 * @param name diisi dengan nama orang yang akan diruat.
 * @param wuku diisi dengan informasi waktu kelahiran orang yang akan diruat. Terdiri dari: Sinta, Landep, Ukir, Kulantir, Tolu, Gumbreg, Wariga, Warigadean, Julungwangi, Sungsang, Dungulan, Kuningan, Langkir, Medangsia, Pujut, Pahang, Krulut, Merakih, Tambir, Medangkungan, Matal, Uye, Menail, Prangbakat, Bala, Ugu, Wayang, Kelawu, Dukut, dan Watugunung.
 * @param rahina diisi dengan informasi sapta wara kelahiran orang yang akan diruat. Terdiri dari: Redite, Soma, Anggara, Budha, Wraspati, Sukra, dan Saniscara.
 * @return 0 jika sukses
 */
int Ruwatan::setup(const std::string name, const std::string wuku, const std::string rahina){
  int idWuku = 0;
  int idRahina = 0;
  this->name = name;
  this->birthDate = rahina + " Wuku " + wuku;
  for (idRahina = 0; idRahina < 8; idRahina++){
    if (rahina == saptaWaraLabel[idRahina]) break;
  }
  if (idRahina >= 7) return 1;
  for (idWuku = 0; idWuku < 31; idWuku++){
    if (wuku == pawukonStr[idWuku]) break;
  }
  if (idWuku >= 30) return 2;
  Wariga wariga;
  int ret = wariga.setup(static_cast<Wariga::PAWUKON_t>(idWuku), static_cast<Wariga::RAHINA_t>(idRahina));
  if (ret == 0){
    ret = this->ekaWara.setParam(RuwatData::EKA_WARA, wariga.ekaWara.getName());
    if (ret == 0) ret = this->dwiWara.setParam(RuwatData::DWI_WARA, wariga.dwiWara.getName());
    if (ret == 0) ret = this->triWara.setParam(RuwatData::TRI_WARA, wariga.triWara.getName());
    if (ret == 0) ret = this->caturWara.setParam(RuwatData::CATUR_WARA, wariga.caturWara.getName());
    if (ret == 0) ret = this->pancaWara.setParam(RuwatData::PANCA_WARA, wariga.pancaWara.getName());
    if (ret == 0) ret = this->sadWara.setParam(RuwatData::SAD_WARA, wariga.sadWara.getName());
    if (ret == 0) ret = this->saptaWara.setParam(RuwatData::SAPTA_WARA, wariga.saptaWara.getName());
    if (ret == 0) ret = this->astaWara.setParam(RuwatData::ASTA_WARA, wariga.astaWara.getName());
    if (ret == 0) ret = this->sangaWara.setParam(RuwatData::SANGA_WARA, wariga.sangaWara.getName());
    if (ret == 0) ret = this->dasaWara.setParam(RuwatData::DASA_WARA, wariga.dasaWara.getName());
    this->birthDate = rahina + " " + wariga.pancaWara.getName() + " Wuku " + wuku;
  }
  else {
    ret += 70;
  }
  return ret;
}

/**
 * @brief Getter untuk mengambil informasi nama file referensi database yang digunakan.
 *
 * Berfungsi untuk melakukan pengambilan informasi nama file referensi database yang digunakan sebagai basis data.
 * @return string nama file referensi database yang digunakan sebagai basis data.
 */
std::string Ruwatan::getDatabase(){
  return this->database;
}

/**
 * @brief Getter untuk mengambil informasi nama Sang Yajamana.
 *
 * Berfungsi untuk melakukan pengambilan informasi nama Sang Yajamana.
 * @return string nama Sang Yajamana yang terakhir dimasukkan pada parameter method __Ruwatan::setup__
 */
std::string Ruwatan::getName(){
  return this->name;
}

/**
 * @brief Getter untuk mengambil informasi waktu kelahiran Sang Yajamana.
 *
 * Berfungsi untuk melakukan pengambilan informasi waktu kelahiran Sang Yajamana.
 * @return string waktu kelahiran Sang Yajamana yang terakhir dimasukkan pada parameter method __Ruwatan::setup__
 */
std::string Ruwatan::getBirthInfo(){
  return this->birthDate;
}