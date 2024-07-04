#include <iostream>
#include <string>

#include "ruwatan.hpp"
#include "tgbot/tgbot.h"
#include "document.hpp"

Ruwatan ruwat;

typedef enum _RUWAT_DATA_TYPE_t {
    RUWAT_TYPE_ALL = 0,
    RUWAT_TYPE_BEBANTEN,
    RUWAT_TYPE_MANTRA
} RUWAT_DATA_TYPE_t;

RUWAT_DATA_TYPE_t ruwatType = RUWAT_TYPE_ALL;

TgBot::ReplyKeyboardMarkup::Ptr contentType(new TgBot::ReplyKeyboardMarkup);
TgBot::ReplyKeyboardMarkup::Ptr documentType(new TgBot::ReplyKeyboardMarkup);
TgBot::InputFile fileTgBot;

std::string fileTitle;

std::string parseWord(const std::string input, int idxWord){
    std::string result = "";
    /* skip word */
    int skipCnt = 0;
    int idx = 0;
    while (skipCnt < idxWord && idx < input.length()) {
        if (input[idx] == ' '){
            skipCnt++;
        }
        idx++;
    }
    if (skipCnt == idxWord){
        while (idx < input.length()){
            if (input[idx] == ' ') break;
            result.append(1, input[idx]);
            idx++;
        }
    }
    return result;
}

void addYadnyaDetailDoc(RUWAT_DATA_TYPE_t ruwatType, Document &doc, std::string type, std::string name, std::string bebanten, std::string mantra){
    if (bebanten.length() == 0 && mantra.length() == 0) return;
    doc.addLine(Document::HEADING_3, type + ": " + name);
    if (bebanten.length() > 0 &&
        (ruwatType == RUWAT_TYPE_ALL || ruwatType == RUWAT_TYPE_BEBANTEN)
    ){
        doc.addLine(Document::HEADING_4, "Bebanten/Sarana");
        doc.addLine(Document::BODY, bebanten);
    }
    if (mantra.length() > 0 &&
        (ruwatType == RUWAT_TYPE_ALL || ruwatType == RUWAT_TYPE_MANTRA)
    ){
        doc.addLine(Document::HEADING_4, "Mantra");
        doc.addLine(Document::BODY, mantra);
    }
}

std::string generateRuwatanDoc(RUWAT_DATA_TYPE_t ruwatType, Document::DOCUMENT_TYPE_t docType){
    Document doc;
    doc.setTitle(fileTitle);
    doc.setHeadingStyle("Arial, sans-serif", "#444444");
    doc.setBodyStyle("Arial, sans-serif", "#222222", 11);
    doc.addLine(Document::HEADING_1, "Ruwatan | Mantra dan Bebanten");
    doc.addLine(Document::BODY, "Ruwatan memiliki arti \"dilepas\" atau \"dibebaskan\". Oleh karena itu, Ruwatan merupakan upacara yang bertujuan membebaskan seseorang yang diruwat dari hukuman atau kutukan dewa ataupun hutang piutang di kehidupan masa lalu yang membawa bahaya.");
    doc.addLine(Document::HEADING_2, "Identitas Yajamana");
    doc.addLine(Document::BODY, "Nama: " + ruwat.getName());
    doc.addLine(Document::BODY, "Kelahiran: " + ruwat.getBirthInfo());
    doc.addLine(Document::HEADING_2, "Ruwatan");
    addYadnyaDetailDoc(ruwatType, doc, "Eka Wara", ruwat.ekaWara.getName(), ruwat.ekaWara.getSacrificeInfo(), ruwat.ekaWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Dwi Wara", ruwat.dwiWara.getName(), ruwat.dwiWara.getSacrificeInfo(), ruwat.dwiWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Tri Wara", ruwat.triWara.getName(), ruwat.triWara.getSacrificeInfo(), ruwat.triWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Catur Wara", ruwat.caturWara.getName(), ruwat.caturWara.getSacrificeInfo(), ruwat.caturWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Panca Wara", ruwat.pancaWara.getName(), ruwat.pancaWara.getSacrificeInfo(), ruwat.pancaWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Sad Wara", ruwat.sadWara.getName(), ruwat.sadWara.getSacrificeInfo(), ruwat.sadWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Sapta Wara", ruwat.saptaWara.getName(), ruwat.saptaWara.getSacrificeInfo(), ruwat.saptaWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Asta Wara", ruwat.astaWara.getName(), ruwat.astaWara.getSacrificeInfo(), ruwat.astaWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Sanga Wara", ruwat.sangaWara.getName(), ruwat.sangaWara.getSacrificeInfo(), ruwat.sangaWara.getSpell());
    addYadnyaDetailDoc(ruwatType, doc, "Dasa Wara", ruwat.dasaWara.getName(), ruwat.dasaWara.getSacrificeInfo(), ruwat.dasaWara.getSpell());
    doc.setDocumentType(docType);
    return doc.getPayload();
}

void createOneColumnKeyboard(const std::vector<std::string>& buttonStrings, TgBot::ReplyKeyboardMarkup::Ptr& kb){
  for (size_t i = 0; i < buttonStrings.size(); ++i) {
    std::vector<TgBot::KeyboardButton::Ptr> row;
    TgBot::KeyboardButton::Ptr button(new TgBot::KeyboardButton);
    button->text = buttonStrings[i];
    row.push_back(button);
    kb->keyboard.push_back(row);
  }
}

int main(int argc, char **argv){
    char *buffer = NULL;
    if (argc < 2){
        printf("cmd: %s <Telegram Bot Token>\n", argv[0]);
        printf("cmd: %s namaYajamana <YYYY-MM-DD>\n", argv[0]);
        printf("cmd: %s namaYajamana <wuku> <rahina>\n", argv[0]);
        exit (0);
    }
    if (argc > 2){
        int ret = 0;
        if (argc == 3){
            ret = ruwat.setup(argv[1], argv[2]);
        }
        else {
            ret = ruwat.setup(argv[1], argv[2], argv[3]);
        }
        if (!ret){
            generateRuwatanDoc(RUWAT_TYPE_ALL, Document::DOCUMENT);
        }
        else {
            std::cout << "Invalid Format dengan return: " << ret << std::endl;
            printf("cmd: %s <Telegram Bot Token>\n", argv[0]);
            printf("cmd: %s namaYajamana <YYYY-MM-DD>\n", argv[0]);
            printf("cmd: %s namaYajamana <wuku> <rahina>\n", argv[0]);
        }
        exit(0);
    }
    TgBot::Bot bot(argv[1]);
    createOneColumnKeyboard({"Banten dan Mantra", "Bebanten", "Mantra"}, contentType);
    createOneColumnKeyboard({"Markdown", "Document", "Back"}, documentType);
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "Ruwat") ||
            StringTools::startsWith(message->text, "ruwat") ||
            StringTools::startsWith(message->text, "ngeruwat") ||
            StringTools::startsWith(message->text, "Ngeruwat")
        ) {
            std::string name = parseWord(message->text, 1);
            std::string btime1 = parseWord(message->text, 2);
            std::string btime2 = parseWord(message->text, 3);
            int ret = 0;
            if (btime2 == ""){
                ret = ruwat.setup(name, btime1);
            }
            else {
                ret = ruwat.setup(name, btime1, btime2);
            }
            if (!ret){
                bot.getApi().sendMessage(message->chat->id, "Pilih Jenis Konten Ruwatan", nullptr, nullptr, contentType);
                fileTitle = ruwat.getName() + " - " + ruwat.getBirthInfo();
            }
            else {
                bot.getApi().sendMessage(message->chat->id, "Invalid Arg\n\n Arg: Ruwat <name> <date> | Ruwat <name> <wuku> <rahina>");
            }
            return;
        }
        else if (StringTools::startsWith(message->text, "Banten dan Mantra")) {
            ruwatType = RUWAT_TYPE_ALL;
            bot.getApi().sendMessage(message->chat->id, "Pilih Jenis Dokumen Banten dan Mantra yang Ingin Dibuat", nullptr, nullptr, documentType);
            fileTitle += " - Lengkap";
            return;
        }
        else if (StringTools::startsWith(message->text, "Bebanten")) {
            ruwatType = RUWAT_TYPE_BEBANTEN;
            bot.getApi().sendMessage(message->chat->id, "Pilih Jenis Dokumen Bebanten yang Ingin Dibuat", nullptr, nullptr, documentType);
            fileTitle += " - Bebanten";
            return;
        }
        else if (StringTools::startsWith(message->text, "Mantra")) {
            ruwatType = RUWAT_TYPE_BEBANTEN;
            bot.getApi().sendMessage(message->chat->id, "Pilih Jenis Dokumen Mantra yang Ingin Dibuat", nullptr, nullptr, documentType);
            fileTitle += " - Mantra";
            return;
        }
        else if (StringTools::startsWith(message->text, "Markdown")) {
            std::transform(fileTitle.begin(), fileTitle.end(), fileTitle.begin(), ::toupper);
            std::string result = generateRuwatanDoc(ruwatType, Document::MARKDOWN);
            fileTgBot.data = result;
            fileTgBot.fileName = fileTitle + ".md";
            fileTgBot.mimeType = "text/utf-8";
            TgBot::InputFile::Ptr fPtr = std::make_shared<TgBot::InputFile>(fileTgBot);
            bot.getApi().sendDocument(message->chat->id, fPtr);
            return;
        }
        else if (StringTools::startsWith(message->text, "Document")) {
            std::transform(fileTitle.begin(), fileTitle.end(), fileTitle.begin(), ::toupper);
            std::string result = generateRuwatanDoc(ruwatType, Document::DOCUMENT);
            fileTgBot.data = result;
            fileTgBot.fileName = fileTitle + ".doc";
            fileTgBot.mimeType = "text/html";
            TgBot::InputFile::Ptr fPtr = std::make_shared<TgBot::InputFile>(fileTgBot);
            bot.getApi().sendDocument(message->chat->id, fPtr);
            return;
        }
        else if (StringTools::startsWith(message->text, "Back")) {
            fileTitle = ruwat.getName() + " - " + ruwat.getBirthInfo();
            bot.getApi().sendMessage(message->chat->id, "Pilih Jenis Konten Ruwatan", nullptr, nullptr, contentType);
            return;
        }
        else {
            bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
            return;
        }
    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}
