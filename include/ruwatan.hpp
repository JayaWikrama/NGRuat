#ifndef __RUWATAN_HPP__
#define __RUWATAN_HPP__

#include <string>
#include "data.hpp"

class Ruwatan {
  private:
    std::string name;
    std::string birthDate;
  public:
    RuwatData ekaWara;
    RuwatData dwiWara;
    RuwatData triWara;
    RuwatData caturWara;
    RuwatData pancaWara;
    RuwatData sadWara;
    RuwatData saptaWara;
    RuwatData astaWara;
    RuwatData sangaWara;
    RuwatData dasaWara;
    /**
     * @brief Default constructor.
     *
     * Berfungsi untuk melakukan setup private data ke nilai default.
     */
    Ruwatan();

    /**
     * @brief Destructor.
     *
     * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
     */
    ~Ruwatan();

    /**
     * @brief Setter untuk setup informasi nama dan data kelahiran orang yang akan diruat.
     *
     * Berfungsi untuk melakukan setup informasi nama dan data kelahiran orang yang akan diruat.
     * @param name diisi dengan nama orang yang akan diruat.
     * @param birthDate diisi dengan informasi waktu kelahiran orang yang akan di ruat. Contoh: disi dengan format YYYY-MM-DD (2000-04-21)
     * @return 0 jika sukses
     */
    int setup(const std::string name, const std::string birthDate);

    /**
     * @brief Setter untuk setup informasi nama dan data kelahiran orang yang akan diruat.
     *
     * Berfungsi untuk melakukan setup informasi nama dan data kelahiran orang yang akan diruat.
     * @param name diisi dengan nama orang yang akan diruat.
     * @param wuku diisi dengan informasi waktu kelahiran orang yang akan diruat. Terdiri dari: Sinta, Landep, Ukir, Kulantir, Tolu, Gumbreg, Wariga, Warigadean, Julungwangi, Sungsang, Dungulan, Kuningan, Langkir, Medangsia, Pujut, Pahang, Krulut, Merakih, Tambir, Medangkungan, Matal, Uye, Menail, Prangbakat, Bala, Ugu, Wayang, Kelawu, Dukut, dan Watugunung.
     * @param rahina diisi dengan informasi sapta wara kelahiran orang yang akan diruat. Terdiri dari: Redite, Soma, Anggara, Budha, Wraspati, Sukra, dan Saniscara.
     * @return 0 jika sukses
     */
    int setup(const std::string name, const std::string wuku, const std::string rahina);

    /**
     * @brief Getter untuk mengambil informasi nama Sang Yajamana.
     *
     * Berfungsi untuk melakukan pengambilan informasi nama Sang Yajamana.
     * @return string nama Sang Yajamana yang terakhir dimasukkan pada parameter method __Ruwatan::setup__
     */
    std::string getName();

    /**
     * @brief Getter untuk mengambil informasi waktu kelahiran Sang Yajamana.
     *
     * Berfungsi untuk melakukan pengambilan informasi waktu kelahiran Sang Yajamana.
     * @return string waktu kelahiran Sang Yajamana yang terakhir dimasukkan pada parameter method __Ruwatan::setup__
     */
    std::string getBirthInfo();
};

#endif