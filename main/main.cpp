#include <iostream>
#include <regex>

#include "ruwatan.hpp"
#include "tgbot/tgbot.h"
#include "document.hpp"

Ruwatan ruwat;

typedef enum _RUWAT_DATA_TYPE_t {
    RUWAT_TYPE_ALL = 0,
    RUWAT_TYPE_BEBANTEN,
    RUWAT_TYPE_MANTRA
} RUWAT_DATA_TYPE_t;

/* Markdown Format */

std::string generateYadnyaDetail(RUWAT_DATA_TYPE_t ruwatType, std::string type, std::string name, std::string bebanten, std::string mantra){
    std::string result = "";
    if (bebanten.length() == 0 && mantra.length() == 0) return result;
    result += "### " + type + ": " + name + "\n";
    if (bebanten.length() > 0){
        if (ruwatType == RUWAT_TYPE_ALL || ruwatType == RUWAT_TYPE_BEBANTEN){
            result += "#### Bebanten/Sarana\n";
            result += bebanten + "\n";
        }
    }
    if (mantra.length() > 0){
        if (ruwatType == RUWAT_TYPE_ALL || ruwatType == RUWAT_TYPE_MANTRA){
            result += "#### Mantra\n";
            result += mantra + "\n";
        }
    }
    return result;
}

std::string generateRuwatanMd(RUWAT_DATA_TYPE_t ruwatType){
    std::string result = "# Ruwatan | Mantra dan Bebanten\n";
    result += "Ruwatan memiliki arti “dilepas” atau “dibebaskan”. Oleh karena itu, Ruwatan merupakan upacara yang bertujuan membebaskan seseorang yang diruwat dari hukuman atau kutukan dewa ataupun hutang piutang di kehidupan masa lalu yang membawa bahaya.\n";
    result += "## Identitas Yajamana\n";
    result += "Nama: " + ruwat.getName() + "\n";
    result += "Kelahiran: " + ruwat.getBirthInfo() + "\n";
    result += "## Ruwatan\n";
    std::string tmp = "";
    tmp = generateYadnyaDetail(ruwatType, "Eka Wara", ruwat.ekaWara.getName(), ruwat.ekaWara.getSacrificeInfo(), ruwat.ekaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Dwi Wara", ruwat.dwiWara.getName(), ruwat.dwiWara.getSacrificeInfo(), ruwat.dwiWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Tri Wara", ruwat.triWara.getName(), ruwat.triWara.getSacrificeInfo(), ruwat.triWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Catur Wara", ruwat.caturWara.getName(), ruwat.caturWara.getSacrificeInfo(), ruwat.caturWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Panca Wara", ruwat.pancaWara.getName(), ruwat.pancaWara.getSacrificeInfo(), ruwat.pancaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Sad Wara", ruwat.sadWara.getName(), ruwat.sadWara.getSacrificeInfo(), ruwat.sadWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Sapta Wara", ruwat.saptaWara.getName(), ruwat.saptaWara.getSacrificeInfo(), ruwat.saptaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Asta Wara", ruwat.astaWara.getName(), ruwat.astaWara.getSacrificeInfo(), ruwat.astaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Sanga Wara", ruwat.sangaWara.getName(), ruwat.sangaWara.getSacrificeInfo(), ruwat.sangaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail(ruwatType, "Dasa Wara", ruwat.dasaWara.getName(), ruwat.dasaWara.getSacrificeInfo(), ruwat.dasaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    result = std::regex_replace(result, std::regex("\n"), "\n\n");
    return result;
}

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

/* Document (HTML) Format */

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

void generateRuwatanDoc(RUWAT_DATA_TYPE_t ruwatType){
    Document doc;
    doc.setTitle(ruwat.getName() + "_" + ruwat.getBirthInfo());
    doc.setHeadingStyle("Arial, sans-serif", "#444444");
    doc.setBodyStyle("Arial, sans-serif", "#222222", 11);
    doc.addLine(Document::HEADING_1, "Ruwatan | Mantra dan Bebanten");
    doc.addLine(Document::BODY, "Ruwatan memiliki arti \"dilepas\" atau \"dibebaskan\". Oleh karena itu, Ruwatan merupakan upacara yang bertujuan membebaskan seseorang yang diruwat dari hukuman atau kutukan dewa ataupun hutang piutang di kehidupan masa lalu yang membawa bahaya.");
    doc.addLine(Document::HEADING_2, "Identitas Yajamana");
    doc.addLine(Document::BODY, "Nama: " + ruwat.getName());
    doc.addLine(Document::BODY, "Kelahiran: " + ruwat.getBirthInfo());
    doc.addLine(Document::HEADING_2, "Ruwatan");
    std::cout << doc.getPayload() << std::endl;
    doc.writeDocument(ruwat.getName() + "_" + ruwat.getBirthInfo() + ".doc");
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
    std::cout << doc.getPayload() << std::endl;
    doc.writeDocument(ruwat.getName() + "_" + ruwat.getBirthInfo() + ".doc");
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
            generateRuwatanDoc(RUWAT_TYPE_ALL);
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
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
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
                std::string result = generateRuwatanMd(RUWAT_TYPE_BEBANTEN);
                std::cout << result << std::endl;
                bot.getApi().sendMessage(message->chat->id, result);
                result = generateRuwatanMd(RUWAT_TYPE_MANTRA);
                std::cout << result << std::endl;
                bot.getApi().sendMessage(message->chat->id, result);
            }
            else {
                bot.getApi().sendMessage(message->chat->id, "Invalid Arg\n\n Arg: Ruwat <name> <date> | Ruwat <name> <wuku> <rahina>");
            }
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
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
