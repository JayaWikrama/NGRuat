#ifndef __PAWUKON_HPP__
#define __PAWUKON_HPP__

#include <ctime>
#include <string>

class Pawukon {
  private:
    unsigned char pawukon;
  public:
    typedef enum _PAWUKON_t {
      WUKU_SINTA = 0,
      WUKU_LANDEP,
      WUKU_UKIR,
      WUKU_KULANTIR,
      WUKU_TOLU,
      WUKU_GUMBREG,
      WUKU_WARIGA,
      WUKU_WARIGADEAN,
      WUKU_JULUNGWANGI,
      WUKU_SUNGSANG,
      WUKU_DUNGULAN,
      WUKU_KUNINGAN,
      WUKU_LANGKIR,
      WUKU_MEDANGSIA,
      WUKU_PUJUT,
      WUKU_PAHANG,
      WUKU_KRULUT,
      WUKU_MERAKIH,
      WUKU_TAMBIR,
      WUKU_MEDANGKUNGAN,
      WUKU_MATAL,
      WUKU_UYE,
      WUKU_MENAIL,
      WUKU_PRANGBAKAT,
      WUKU_BALA,
      WUKU_UGU,
      WUKU_WAYANG,
      WUKU_KELAWU,
      WUKU_DUKUT,
      WUKU_WATUGUNUNG,
      WUKU_UNKNOWN
    } PAWUKON_t;

    typedef enum _RAHINA_t {
      REDITE = 0,
      SOMA,
      ANGGARA,
      BUDHA,
      WRASPATI,
      SUKRA,
      SANISCARA,
      UNKNOWN
    } RAHINA_t;

    /**
     * @brief Default constructor.
     *
     * Berfungsi untuk melakukan setup waktu dan pawukon ke waktu saat object dibuat.
     */
    Pawukon();

    /**
     * @brief Custom constructor.
     *
     * Berfungsi untuk melakukan setup waktu dan pawukon ke waktu yang di-setup pada parameter input.
     * @param currentTime dalam bentuk epoch timestamp.
     */
    Pawukon(time_t currentTime);

    /**
     * @brief Custom constructor.
     *
     * Berfungsi untuk melakukan direct setup pawukon dan juga rahina.
     * @param pawukon merepresentasikan ID dari pawukon (dimulai dari 0 hingga 29).
     * @param rahina merepresentasikan ID dari rahina (dimulai dari 0 hingga 6).
     */
    Pawukon(PAWUKON_t pawukon, RAHINA_t rahina);

    /**
     * @brief Destructor.
     *
     * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
     */
    ~Pawukon();

    /**
     * @brief Setter untuk waktu.
     *
     * Berfungsi untuk melakukan setup waktu dan juga pawukon berdasarkan waktu yang di-input pada parameter input.
     * @param currentTime dalam bentuk epoch timestamp.
     */
    void setTime(time_t currentTime);

    /**
     * @brief Setter untuk pawukon dan rahina.
     *
     * Berfungsi untuk melakukan direct setup pawukon dan juga rahina.
     * @param pawukon merepresentasikan ID dari pawukon (dimulai dari 0 hingga 29).
     * @param rahina merepresentasikan ID dari rahina (dimulai dari 0 hingga 6).
     */
    void setPawukonRahina(PAWUKON_t pawukon, RAHINA_t rahina);

    /**
     * @brief Getter untuk pawukon.
     *
     * Berfungsi untuk mengambil nomor identitas pawukon yang dimulai dari 0 hingga 29.
     * @return nomor identitas pawukon
     */
    PAWUKON_t getPawukon();

    /**
     * @brief Getter untuk rahina.
     *
     * Berfungsi untuk mengambil nomor identitas rahina yang dimulai dari 0 hingga 6.
     * @return nomor identitas rahina
     * @return WUKU_UNKNOWN jika data yang sebelumnya diinput salah
     */
    RAHINA_t getRahina();

    /**
     * @brief Getter untuk pawukon.
     *
     * Berfungsi untuk mengambil label/nama pawukon yang dimulai dari 0 hingga 29.
     * @return label/nama pawukon dalam bentuk string.
     * @return UNKNOWN jika data yang sebelumnya diinput salah
     */
    std::string getPawukonStr();

    /**
     * @brief Getter untuk neptu pawukon.
     *
     * Berfungsi untuk mengambil data neptu yang dimiliki oleh pawukon.
     * @return neptu pawukon.
     * @return unknown jika data yang sebelumnya diinput salah
     */
    unsigned int getPawukonUrip();
};

#endif