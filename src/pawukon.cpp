#include <iostream>
#include <string>
#include <string.h>
#include "pawukon.hpp"

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
  "Watugunung"
};

static const unsigned char pawukonUrip[] = {
  7,
  1,
  4,
  6,
  5,
  8,
  9,
  3,
  7,
  1,
  4,
  6,
  5,
  8,
  9,
  3,
  7,
  1,
  4,
  6,
  5,
  8,
  9,
  3,
  7,
  1,
  4,
  6,
  5,
  8
};

/**
 * @brief Default constructor.
 *
 * Berfungsi untuk melakukan setup waktu dan pawukon ke waktu saat object dibuat.
 */
Pawukon::Pawukon(){
  this->setTime(time(NULL));
}

/**
 * @brief Custom constructor.
 *
 * Berfungsi untuk melakukan setup waktu dan pawukon ke waktu yang di-setup pada parameter input.
 * @param currentTime dalam bentuk epoch timestamp.
 */
Pawukon::Pawukon(time_t currentTime){
  this->setTime(currentTime);
}

/**
 * @brief Custom constructor.
 *
 * Berfungsi untuk melakukan direct setup pawukon dan juga rahina.
 * @param pawukon merepresentasikan ID dari pawukon (dimulai dari 0 hingga 29).
 * @param rahina merepresentasikan ID dari rahina (dimulai dari 0 hingga 6).
 */
Pawukon::Pawukon(PAWUKON_t pawukon, RAHINA_t rahina){
  this->pawukon = static_cast<unsigned char>(pawukon * 7 + rahina);
}

/**
 * @brief Destructor.
 *
 * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
 */
Pawukon::~Pawukon(){

}

/**
 * @brief Setter untuk waktu.
 *
 * Berfungsi untuk melakukan setup waktu dan juga pawukon berdasarkan waktu yang di-input pada parameter input.
 * @param currentTime dalam bentuk epoch timestamp.
 */
void Pawukon::setTime(time_t currentTime){
  struct tm tmBalineseCalendarRef;
  memset(&tmBalineseCalendarRef, 0x00, sizeof(struct tm));
  tmBalineseCalendarRef.tm_mday = 6;
  tmBalineseCalendarRef.tm_mon = 4;
  tmBalineseCalendarRef.tm_year = 0;
  tmBalineseCalendarRef.tm_hour = 0;
  tmBalineseCalendarRef.tm_min = 0;
  tmBalineseCalendarRef.tm_sec = 0;
  time_t balineseCalendarRef = mktime(&tmBalineseCalendarRef);
  this->pawukon = static_cast<unsigned char>(((currentTime - balineseCalendarRef)/86400) % 210);
}

/**
 * @brief Setter untuk pawukon dan rahina.
 *
 * Berfungsi untuk melakukan direct setup pawukon dan juga rahina.
 * @param pawukon merepresentasikan ID dari pawukon (dimulai dari 0 hingga 29).
 * @param rahina merepresentasikan ID dari rahina (dimulai dari 0 hingga 6).
 */
void Pawukon::setPawukonRahina(PAWUKON_t pawukon, RAHINA_t rahina){
  if (pawukon >= WUKU_SINTA &&
      pawukon <= WUKU_WATUGUNUNG &&
      rahina >= REDITE &&
      rahina <= SANISCARA
  ){
    this->pawukon = static_cast<unsigned char>(pawukon * 7 + rahina);
  }
  else {
    this->pawukon = 211;
  }
}

/**
 * @brief Getter untuk pawukon.
 *
 * Berfungsi untuk mengambil nomor identitas pawukon yang dimulai dari 0 hingga 29.
 * @return nomor identitas pawukon jika sukses
 * @return WUKU_UNKNOWN jika data yang sebelumnya diinput salah
 */
Pawukon::PAWUKON_t Pawukon::getPawukon(){
  if (this->pawukon < 210) return static_cast<PAWUKON_t>(this->pawukon / 7);
  return WUKU_UNKNOWN;
}

/**
 * @brief Getter untuk rahina.
 *
 * Berfungsi untuk mengambil nomor identitas rahina yang dimulai dari 0 hingga 6.
 * @return nomor identitas rahina
 * @return UNKNOWN jika data yang sebelumnya diinput salah
 */
Pawukon::RAHINA_t Pawukon::getRahina(){
  if (this->pawukon < 210) return static_cast<RAHINA_t>(this->pawukon % 7);
  return UNKNOWN;
}

/**
 * @brief Getter untuk pawukon.
 *
 * Berfungsi untuk mengambil label/nama pawukon yang dimulai dari 0 hingga 29.
 * @return label/nama pawukon dalam bentuk string.
 */
std::string Pawukon::getPawukonStr(){
  if (this->pawukon < 210) return pawukonStr[this->pawukon / 7];
  return "unknown";
}

/**
 * @brief Getter untuk neptu pawukon.
 *
 * Berfungsi untuk mengambil data neptu yang dimiliki oleh pawukon.
 * @return neptu pawukon.
 */
unsigned int Pawukon::getPawukonUrip(){
  if (this->pawukon < 210) return static_cast<unsigned int>(pawukonUrip[this->pawukon / 7]);
  return 0;
}