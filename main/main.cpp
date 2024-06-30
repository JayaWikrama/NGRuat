#include <iostream>
#include <regex>

#include "ruwatan.hpp"

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

int main(int argc, char **argv){
    char *buffer = NULL;
    if (argc < 3){
        printf("cmd: %s namaYajamana <YYYY-MM-DD>\n", argv[0]);
        printf("cmd: %s namaYajamana <wuku> <rahina>\n", argv[0]);
        exit (0);
    }
    int ret = 0;
    if (argc == 3){
        ret = ruwat.setup(argv[1], argv[2]);
    }
    else {
        ret = ruwat.setup(argv[1], argv[2], argv[3]);
    }
    if (!ret){
        std::cout << generateRuwatanMd() << std::endl;
    }
    else {
        std::cout << "Invalid Format dengan return: " << ret << std::endl;
        printf("cmd: %s <YYYY-MM-DD>\n", argv[0]);
        printf("cmd: %s <wuku> <rahina>\n", argv[0]);
    }
    return 0;
}
