#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <string>

class RuwatData {
  private:
    std::string database;
    std::string name;
    std::string kelahiran;
    std::string bebanten;
    std::string mantra;
  public:
    typedef enum _GROUP_t {
      EKA_WARA = 0,
      DWI_WARA,
      TRI_WARA,
      CATUR_WARA,
      PANCA_WARA,
      SAD_WARA,
      SAPTA_WARA,
      ASTA_WARA,
      SANGA_WARA,
      DASA_WARA
    } GROUP_t;
    /**
     * @brief Default constructor.
     *
     * Berfungsi untuk melakukan setup private data ke nilai default.
     */
    RuwatData();

    /**
     * @brief Destructor.
     *
     * Berfungsi untuk melakukan release setiap memory yang dialokasikan.
     */
    ~RuwatData();

    /**
     * @brief Setter untuk file database.
     *
     * Berfungsi untuk melakukan setup database yang digunakan sebagai referensi informasi.
     * @param db database.
     */
    void setDatabase(const std::string db);
    
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
    int setParam(RuwatData::GROUP_t type, const std::string name);

    /**
     * @brief Setter untuk informasi latar belakang kelahiran.
     *
     * Berfungsi untuk melakukan setup informasi latar belakang kelahiran.
     * @param info value.
     */
    void setBirthInfo(const std::string info);

    /**
     * @brief Setter untuk informasi yadnya yang perlu dilakukan.
     *
     * Berfungsi untuk melakukan setup informasi yadnya yang perlu dilakukan.
     * @param info value.
     */
    void setSacrificeInfo(const std::string info);

    /**
     * @brief Setter untuk informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
     *
     * Berfungsi untuk melakukan setup informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
     * @param info value.
     */
    void setSpell(const std::string info);

    /**
     * @brief Getter untuk mengambil informasi nama wewaran atau pawukon.
     *
     * Berfungsi untuk melakukan pengambilan data informasi nama wewaran atau pawukon.
     * @return string informasi nama wewaran atau pawukon.
     */
    std::string getName();

    /**
     * @brief Getter untuk mengambil informasi latar belakang kelahiran.
     *
     * Berfungsi untuk melakukan pengambilan data informasi latar belakang kelahiran.
     * @return string informasi kelahiran yang meliputi latar belakang atau tujuan kelahiran.
     */
    std::string getBirthInfo();

    /**
     * @brief Getter untuk mengambil informasi yadnya yang perlu dilakukan.
     *
     * Berfungsi untuk melakukan pengambilan data informasi yadnya yang perlu dilakukan yang meliputi berbagai sarana dan pengorbanan yang perlu dilakukan.
     * @return string informasi yadnya yang diperlukan.
     */
    std::string getSacrificeInfo();

    /**
     * @brief Getter untuk mengambil informasi Mantra yang digunakan dalam pelaksanaan yadnya terkait.
     *
     * Berfungsi untuk melakukan pengambilan data informasi informasi Mantra yang digunakan dalam pelaksanaan yadnya berdasarkan sarana dan pengorbanan yang diperoleh melalui method __RuwatData::getSacrificeInfo__.
     * @return string Mantra.
     */
    std::string getSpell();
};

#endif 