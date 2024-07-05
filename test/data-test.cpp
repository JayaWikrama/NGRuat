#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sys/time.h>

#include "data.hpp"

std::string wewaranTypeStr[] = {
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

std::string exec(const char *_cmd) {
    char buffer[128];
    std::string result = "";
    std::string cmd(_cmd);
    cmd += " > /dev/null 2>&1";
    if (system(cmd.c_str())){
        result = "error";
        return result;
    }
    FILE* pipe = popen(_cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    if (result.length() > 0){
        if (result[result.length() - 1] == '\n'){
            result.pop_back();
        }
    }
    return result;
}

class DataTest:public::testing::Test {
protected:
    RuwatData data;

    void SetUp() override {
        // tidak ada kebutuhan pre-set
    }

    void TearDown() override {
        // tidak ada kebutuhan post-set
    }
};

/* Test Case untuk Constructor */

TEST_F(DataTest, DefaultConstructor1) {
    // Tes untuk default constructor
    ASSERT_EQ(data.getName(), "");
    ASSERT_EQ(data.getBirthBackground(), "");
    ASSERT_EQ(data.getSacrificeInfo(), "");
    ASSERT_EQ(data.getSpell(), "");
}

/* Test Case untuk Setter dan Getter */

TEST_F(DataTest, SetterAndGetter_0) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::EKA_WARA;
    std::string wewaran = "Luang";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_1) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Pasah";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_2) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Pasah";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_3) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Beteng";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_4) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Beteng";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_5) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Kajeng";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_6) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::TRI_WARA;
    std::string wewaran = "Kajeng";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_7) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Sri";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_8) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Sri";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_9) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Laba";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_10) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Laba";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_11) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Jaya";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_12) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Jaya";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_13) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Menala";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_14) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::CATUR_WARA;
    std::string wewaran = "Menala";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_15) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Keliwon";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_16) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Keliwon";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_17) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Pahing";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_18) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Pahing";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_19) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Pon";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_20) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Pon";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_21) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Umanis";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_22) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Umanis";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_23) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Wage";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_24) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::PANCA_WARA;
    std::string wewaran = "Wage";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_25) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Aryang";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_26) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Aryang";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_27) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Maulu";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_28) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Maulu";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_29) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Paniron";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_30) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Paniron";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_31) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Tungleh";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_32) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Tungleh";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_33) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Urukung";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_34) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Urukung";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_35) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Was";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_36) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAD_WARA;
    std::string wewaran = "Was";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_37) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Anggara";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_38) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Anggara";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_39) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Budha";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_40) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Budha";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_41) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Redite";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_42) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Redite";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_43) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Saniscara";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_44) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Saniscara";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_45) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Soma";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_46) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Soma";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_47) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Sukra";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_48) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Sukra";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_49) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Wraspati";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_50) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SAPTA_WARA;
    std::string wewaran = "Wraspati";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_51) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Brahma";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_52) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Brahma";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_53) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Guru";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_54) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Guru";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_55) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Indra";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_56) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Indra";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_57) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Kala";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_58) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Kala";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_59) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Rudra";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_60) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Rudra";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_61) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Sri";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_62) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Sri";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_63) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Uma";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_64) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Uma";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_65) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Yama";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_66) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::ASTA_WARA;
    std::string wewaran = "Yama";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_67) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Dadi";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_68) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Dadi";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_69) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Dangu";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_70) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Dangu";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_71) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Dangu";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_72) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Erengan";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_73) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Erengan";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_74) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Erengan";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_75) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Gigis";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_76) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Jangur";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_77) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Jangur";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_78) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Jangur";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_79) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Nohan";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_80) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Nohan";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_81) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Nohan";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_82) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Ogan";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_83) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Ogan";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_84) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Ogan";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_85) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Tulus";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_86) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Tulus";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_87) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Urungan";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_88) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Urungan";
    std::string type = "Kelahiran";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getBirthBackground();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_89) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::SANGA_WARA;
    std::string wewaran = "Urungan";
    std::string type = "Mantra";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSpell();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_90) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::DWI_WARA;
    std::string wewaran = "Menga";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}

TEST_F(DataTest, SetterAndGetter_91) {
    std::string database = "../asset/database/ruwatan.db";
    RuwatData::GROUP_t group = RuwatData::DWI_WARA;
    std::string wewaran = "Pepet";
    std::string type = "Bebanten";
    data.setDatabase(database);
    data.setParam(group, wewaran);
    std::string systemCmd = "sqlite3 " + database + 
                            " \"SELECT detail FROM ruwatan_tbl" +
                            " WHERE type = \'" + type +
                            "\' AND wewaran_type = \'" + wewaranTypeStr[group] +
                            "\' AND wewaran = \'" + wewaran + "\';\"";
    std::string ref = exec(systemCmd.c_str());
    std::string result = data.getSacrificeInfo();
    ASSERT_EQ(result, ref);
}