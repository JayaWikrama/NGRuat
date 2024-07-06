#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sys/time.h>

#include "ruwatan.hpp"

class RuwatanTest:public::testing::Test {
protected:
    Ruwatan ruwatan;

    void SetUp() override {
        // tidak ada kebutuhan pre-set
    }

    void TearDown() override {
        // tidak ada kebutuhan post-set
    }
};

/* Test Case untuk Constructor */

TEST_F(RuwatanTest, DefaultConstructor1) {
    // Tes untuk default constructor
    ASSERT_EQ(ruwatan.getName(), "");
    ASSERT_EQ(ruwatan.getBirthInfo(), "");
}

/* Test Case untuk Setter dan Getter */

TEST_F(RuwatanTest, SetterAndGetter_setup1) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "2000-02-29"), 0);
    ASSERT_EQ(ruwatan.getName(), "Jaya");
    ASSERT_EQ(ruwatan.getBirthInfo(), "Anggara Kliwon Wuku Tambir");
}

TEST_F(RuwatanTest, SetterAndGetter_setup2) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "Landep", "Saniscara"), 0);
    ASSERT_EQ(ruwatan.getName(), "Jaya");
    ASSERT_EQ(ruwatan.getBirthInfo(), "Saniscara Kliwon Wuku Landep");
}

TEST_F(RuwatanTest, SetterAndGetter_setupNegative1) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "2001-02-29"), 79);
}

TEST_F(RuwatanTest, SetterAndGetter_setupNegative2) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "2001-04-31"), 79);
}

TEST_F(RuwatanTest, SetterAndGetter_setupNegative3) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "Sinta", "soma"), 1);
}

TEST_F(RuwatanTest, SetterAndGetter_setupNegative4) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase(database);
    ASSERT_EQ(ruwatan.setup("Jaya", "sinta", "Soma"), 2);
}

TEST_F(RuwatanTest, SetterAndGetter_setupNegative5) {
    std::string database = "../asset/database/ruwatan.db";
    ruwatan.ekaWara.setDatabase(database);
    ruwatan.dwiWara.setDatabase(database);
    ruwatan.triWara.setDatabase(database);
    ruwatan.caturWara.setDatabase(database);
    ruwatan.pancaWara.setDatabase(database);
    ruwatan.sadWara.setDatabase(database);
    ruwatan.saptaWara.setDatabase(database);
    ruwatan.astaWara.setDatabase(database);
    ruwatan.sangaWara.setDatabase(database);
    ruwatan.dasaWara.setDatabase("unknown");
    ASSERT_EQ(ruwatan.setup("Jaya", "2001-04-30"), 2);
}