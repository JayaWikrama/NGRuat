#include <iostream>
#include <string.h>
#include "data.hpp"

#include <pthread.h>
#include <sqlite3.h>
#include "data.hpp"

static pthread_mutex_t dmutex = PTHREAD_MUTEX_INITIALIZER;

static const std::string groupTypeStr[] = {
  "eka",
  "dwi",
  "tri",
  "catur",
  "panca",
  "sad",
  "sapta",
  "asta",
  "sanga",
  "dasa"
};

static int ___callback(void *_ptr, int _argc, char **_argv, char **_azColName){
  RuwatData *data = static_cast<RuwatData *>(_ptr);
  int idx = 0;
  for (idx = 0; idx < _argc; idx += 2){
    if (memcmp(_argv[idx], "Bebanten", 7) == 0){
      data->setSacrificeInfo(std::string(_argv[idx + 1]));
    }
    else if (memcmp(_argv[idx], "Mantra", 6) == 0){
      data->setSpell(std::string(_argv[idx + 1]));
    }
    else if (memcmp(_argv[idx], "Kelahiran", 9) == 0){
      data->setBirthBackground(std::string(_argv[idx + 1]));
    }
  }
  return 0;
}

/**
 * @brief Default constructor.
 *
 * Berfungsi untuk melakukan setup private data ke nilai default.
 */
RuwatData::RuwatData(){
  this->database = "";
  this->kelahiran = "";
  this->bebanten = "";
  this->mantra = "";
}

/**
 * @brief Destructor.
 *
 * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
 */
RuwatData::~RuwatData(){

}

/**
 * @brief Setter untuk file database.
 *
 * Berfungsi untuk melakukan setup database yang digunakan sebagai referensi informasi.
 * @param db database.
 */
void RuwatData::setDatabase(const std::string db){
  this->database = db;
}

/**
 * @brief Setter untuk parameter referensi pengambilan informasi dari database.
 *
 * Berfungsi untuk melakukan setup parameter tipe wewaran/pawukon dan juga nama wewaran/pawukon yang digunakan sebagai parameter dalam mengambil informasi dari database.
 * @param type merepresentasikan tipe wewaran/pawukon.
 * @param name nama dari wewaran/pawukon.
 * @return 0 jika sukses
 * @return 1 jika gagal membuka database
 * @return 2 jika proses query database gagal
 */
int RuwatData::setParam(RuwatData::GROUP_t type, const std::string name){
  pthread_mutex_lock(&dmutex);
  char sql[128];
  sqlite3 *db = NULL;
  if (sqlite3_open(this->database.c_str(), &db) != SQLITE_OK) {
    if (db != NULL) {
      sqlite3_close(db);
      db = NULL;
    }
    pthread_mutex_unlock(&dmutex);
    return 1;
  }
  memset(sql, 0x00, sizeof(sql));
  sprintf(sql,
          "SELECT type, detail "
          "FROM ruwatan_tbl "
          "WHERE wewaran_type == '%s' AND wewaran == '%s';",
          groupTypeStr[type].c_str(),
          name.c_str());
  if (sqlite3_exec(db, sql, ___callback, this, NULL) != SQLITE_OK){
    sqlite3_close(db);
    db = NULL;
    pthread_mutex_unlock(&dmutex);
    return 2;
  }
  sqlite3_close(db);
  db = NULL;
  this->name = name;
  pthread_mutex_unlock(&dmutex);
  return 0;
}

/**
 * @brief Setter untuk informasi latar belakang kelahiran.
 *
 * Berfungsi untuk melakukan setup informasi latar belakang kelahiran.
 * @param info value.
 */
void RuwatData::setBirthBackground(const std::string info){
  this->kelahiran = info;
}

/**
 * @brief Setter untuk informasi yadnya yang perlu dilakukan.
 *
 * Berfungsi untuk melakukan setup informasi yadnya yang perlu dilakukan.
 * @param info value.
 */
void RuwatData::setSacrificeInfo(const std::string info){
  this->bebanten = info;
}

/**
 * @brief Setter untuk informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
 *
 * Berfungsi untuk melakukan setup informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
 * @param info value.
 */
void RuwatData::setSpell(const std::string info){
  this->mantra = info;
}

/**
 * @brief Getter untuk mengambil informasi nama wewaran atau pawukon.
 *
 * Berfungsi untuk melakukan pengambilan data informasi nama wewaran atau pawukon.
 * @return string informasi nama wewaran atau pawukon.
 */
std::string RuwatData::getName(){
  return this->name;
}

/**
 * @brief Getter untuk mengambil informasi latar belakang kelahiran.
 *
 * Berfungsi untuk melakukan pengambilan data informasi latar belakang kelahiran.
 * @return string informasi kelahiran yang meliputi latar belakang atau tujuan kelahiran.
 */
std::string RuwatData::getBirthBackground(){
  return this->kelahiran;
}

/**
 * @brief Getter untuk mengambil informasi yadnya yang perlu dilakukan.
 *
 * Berfungsi untuk melakukan pengambilan data informasi yadnya yang perlu dilakukan yang meliputi berbagai sarana dan pengorbanan yang perlu dilakukan.
 * @return string informasi yadnya yang diperlukan.
 */
std::string RuwatData::getSacrificeInfo(){
  return this->bebanten;
}

/**
 * @brief Getter untuk mengambil informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
 *
 * Berfungsi untuk melakukan pengambilan data informasi informasi Mantra yang digunakan dalam pelaksanaan yadnya berdasarkan sarana dan pengorbanan yang diperoleh melalui method __RuwatData::getSacrificeInfo__.
 * @return string Mantra.
 */
std::string RuwatData::getSpell(){
  return this->mantra;
}