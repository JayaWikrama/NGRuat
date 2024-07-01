#include <iostream>
#include <regex>

#include "ruwatan.hpp"
#include "tgbot/tgbot.h"

Ruwatan ruwat;

std::string generateYadnyaDetail(std::string type, std::string name, std::string bebanten, std::string mantra){
    std::string result = "";
    if (bebanten.length() == 0 && mantra.length() == 0) return result;
    result += "### " + type + ": " + name + "\n";
    if (bebanten.length() > 0){
        result += "#### Bebanten/Sarana\n";
        result += bebanten + "\n";
    }
    if (mantra.length() > 0){
        result += "#### Mantra\n";
        result += mantra + "\n";
    }
    return result;
}

std::string generateRuwatanMd(){
    std::string result = "# Ruwatan | Mantra dan Bebanten\n";
    result += "Ruwatan memiliki arti “dilepas” atau “dibebaskan”. Oleh karena itu, Ruwatan merupakan upacara yang bertujuan membebaskan seseorang yang diruwat dari hukuman atau kutukan dewa ataupun hutang piutang di kehidupan masa lalu yang membawa bahaya.\n";
    result += "## Identitas Yajamana\n";
    result += "Nama: " + ruwat.getName() + "\n";
    result += "Kelahiran: " + ruwat.getBirthInfo() + "\n";
    result += "## Ruwatan\n";
    std::string tmp = "";
    tmp = generateYadnyaDetail("Eka Wara", ruwat.ekaWara.getName(), ruwat.ekaWara.getSacrificeInfo(), ruwat.ekaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Dwi Wara", ruwat.dwiWara.getName(), ruwat.dwiWara.getSacrificeInfo(), ruwat.dwiWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Tri Wara", ruwat.triWara.getName(), ruwat.triWara.getSacrificeInfo(), ruwat.triWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Catur Wara", ruwat.caturWara.getName(), ruwat.caturWara.getSacrificeInfo(), ruwat.caturWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Panca Wara", ruwat.pancaWara.getName(), ruwat.pancaWara.getSacrificeInfo(), ruwat.pancaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Sad Wara", ruwat.sadWara.getName(), ruwat.sadWara.getSacrificeInfo(), ruwat.sadWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Sapta Wara", ruwat.saptaWara.getName(), ruwat.saptaWara.getSacrificeInfo(), ruwat.saptaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Asta Wara", ruwat.astaWara.getName(), ruwat.astaWara.getSacrificeInfo(), ruwat.astaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Sanga Wara", ruwat.sangaWara.getName(), ruwat.sangaWara.getSacrificeInfo(), ruwat.sangaWara.getSpell());
    if (tmp.length() > 5) result += tmp;
    tmp = generateYadnyaDetail("Dasa Wara", ruwat.dasaWara.getName(), ruwat.dasaWara.getSacrificeInfo(), ruwat.dasaWara.getSpell());
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

int main(int argc, char **argv){
    char *buffer = NULL;
    if (argc < 2){
        printf("cmd: %s <Telegram Bot Token>\n", argv[0]);
        exit (0);
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
                std::string result = generateRuwatanMd();
                std::cout << result << std::endl;
                bot.getApi().sendMessage(message->chat->id, ruwat.getName() + " " + ruwat.getBirthInfo());
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
