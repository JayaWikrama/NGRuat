#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sys/time.h>

#include "document.hpp"

class DocumentTest:public::testing::Test {
protected:
    Document document;

    void SetUp() override {
        // tidak ada kebutuhan pre-set
    }

    void TearDown() override {
        // tidak ada kebutuhan post-set
    }
};

/* Test Case untuk Constructor */

TEST_F(DocumentTest, DefaultConstructor1) {
    // Tes untuk default constructor
    ASSERT_EQ(document.getPayload(), "");
}

/* Test Case untuk Setter dan Getter */

TEST_F(DocumentTest, SetterAndGetter_defaultPlainText) {
    document.setDocumentType(Document::PLAIN_TEXT);
    ASSERT_EQ(document.getPayload(), "");
}

TEST_F(DocumentTest, SetterAndGetter_defaultDocument) {
    document.setDocumentType(Document::DOCUMENT);
    ASSERT_EQ(document.getPayload(), "<html>"
                                        "<head>"
                                            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">"
                                            "<title>New Document</title>"
                                            "<style>"
                                                "h1, h2, h3, h4 {font-family:Arial, sans-serif;color:#555555;}"
                                                "p {font-family:Arial, sans-serif;font-size:12pt;color:#000000;}"
                                            "</style>"
                                        "</head>"
                                        "<body>\n\n</body>"
                                        "</html>");
}

TEST_F(DocumentTest, SetterAndGetter_defaultMarkdown) {
    document.setDocumentType(Document::MARKDOWN);
    ASSERT_EQ(document.getPayload(), "");
}

TEST_F(DocumentTest, SetterAndGetter_customPlainText) {
    document.setTitle("My Document");
    document.setHeadingStyle("Calibri", "#666666");
    document.setBodyStyle("Sans", "#0000FF", 16);
    document.addLine(Document::HEADING_1, "head-1");
    document.addLine(Document::HEADING_2, "head-2");
    document.addLine(Document::HEADING_3, "head-3-0\nhead-3-1\n");
    document.addLine(Document::HEADING_4, "head-4\n");
    document.addLine(Document::BODY, "body-0\nbody-1\n\n");
    document.setDocumentType(Document::PLAIN_TEXT);
    ASSERT_EQ(document.getPayload(), "head-1\n"
                                     "head-2\n"
                                     "head-3-0\n"
                                     "head-3-1\n"
                                     "head-4\n"
                                     "body-0\n"
                                     "body-1\n"
                                     "\n");
}

TEST_F(DocumentTest, SetterAndGetter_customDocument) {
    document.setTitle("My Document");
    document.setHeadingStyle("Calibri", "#666666");
    document.setBodyStyle("Sans", "#0000FF", 16);
    document.addLine(Document::HEADING_1, "head-1");
    document.addLine(Document::HEADING_2, "head-2");
    document.addLine(Document::HEADING_3, "head-3-0\nhead-3-1\n");
    document.addLine(Document::HEADING_4, "head-4\n");
    document.addLine(Document::BODY, "body-0\nbody-1\n\n");
    document.setDocumentType(Document::DOCUMENT);
    ASSERT_EQ(document.getPayload(), "<html>"
                                        "<head>"
                                            "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">"
                                            "<title>My Document</title>"
                                            "<style>"
                                                "h1, h2, h3, h4 {font-family:Calibri;color:#666666;}"
                                                "p {font-family:Sans;font-size:16pt;color:#0000FF;}"
                                            "</style>"
                                        "</head>"
                                        "<body>\n"
                                        "<h1>head-1</h1>"
                                        "<h2>head-2</h2>"
                                        "<h3>head-3-0</h3>"
                                        "<h3>head-3-1</h3>"
                                        "<h4>head-4</h4>"
                                        "<p>body-0</p>"
                                        "<p>body-1</p>"
                                        "<p></p>"
                                        "\n</body>"
                                        "</html>");
}

TEST_F(DocumentTest, SetterAndGetter_customMarkdown) {
    document.setTitle("My Document");
    document.setHeadingStyle("Calibri", "#666666");
    document.setBodyStyle("Sans", "#0000FF", 16);
    document.addLine(Document::HEADING_1, "head-1");
    document.addLine(Document::HEADING_2, "head-2");
    document.addLine(Document::HEADING_3, "head-3-0\nhead-3-1\n");
    document.addLine(Document::HEADING_4, "head-4\n");
    document.addLine(Document::BODY, "body-0\nbody-1\n\n");
    document.setDocumentType(Document::MARKDOWN);
    ASSERT_EQ(document.getPayload(), "# head-1\n\n"
                                     "## head-2\n\n"
                                     "### head-3-0\n\n"
                                     "### head-3-1\n\n"
                                     "#### head-4\n\n"
                                     "body-0\n\n"
                                     "body-1\n\n"
                                     "\n\n");
}