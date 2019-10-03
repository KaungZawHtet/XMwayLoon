//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#include "../include/number.h"
#include <regex>
#include <iostream>

typedef Xlotgative::Number X_Number;

X_Number::Number() {
    this->myanNum = std::make_unique<type_myanNum>();


    this->myanNum->operator[]("0") = "၀";
    this->myanNum->operator[]("1") = "၁";
    this->myanNum->operator[]("2") = "၂";
    this->myanNum->operator[]("3") = "၃";
    this->myanNum->operator[]("4") = "၄";
    this->myanNum->operator[]("5") = "၅";
    this->myanNum->operator[]("6") = "၆";
    this->myanNum->operator[]("7") = "၇";
    this->myanNum->operator[]("8") = "၈";
    this->myanNum->operator[]("9") = "၉";


}

Xlotgative::ptr_string X_Number::convertEngNumToMyan(const std::string &engNum) {


    std::string result = "";

    std::for_each(engNum.begin(), engNum.end(), [this, &result](auto &engChar) {


        std::regex numRegex("[0-9]{1,2}");
        std::string str_Cache;
        str_Cache.push_back(engChar);


        if (std::regex_match(str_Cache, numRegex)) {
        auto iterator = this->myanNum->find(str_Cache);
        result += iterator->second;
    } else result +=str_Cache;

    });


    return std::make_unique<std::string>(result);

}



