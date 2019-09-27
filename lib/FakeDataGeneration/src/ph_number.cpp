//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#include "../include/ph_number.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
using namespace Xlotgative;

PhoneNumber::PhoneNumber() {
    this->myanmarNumberKeywords["0"] = pair<string, string>("၀", "၀");
    this->myanmarNumberKeywords["1"] = pair<string, string>("၁", "၁");
    this->myanmarNumberKeywords["2"] = pair<string, string>("၂", "၂");
    this->myanmarNumberKeywords["3"] = pair<string, string>("၃", "၃");
    this->myanmarNumberKeywords["4"] = pair<string, string>("၄", "၄");
    this->myanmarNumberKeywords["5"] = pair<string, string>("၅", "၅");
    this->myanmarNumberKeywords["6"] = pair<string, string>("၆", "၆");
    this->myanmarNumberKeywords["7"] = pair<string, string>("၇", "၇");
    this->myanmarNumberKeywords["8"] = pair<string, string>("၈", "၈");
    this->myanmarNumberKeywords["9"] = pair<string, string>("၉", "၉");

}

void PhoneNumber::convertEnglishNumberToMyanmar(std::string &englishNumber, string &encoding) {
    string result;

    std::for_each(englishNumber.begin(), englishNumber.end(), [this, encoding](auto &englishCharacter) {

        string stringCache;
        stringCache.push_back(englishCharacter);
        auto iterator = this->myanmarNumberKeywords.find(stringCache);

        if (encoding == UNICODE)cout << iterator->second.first;
        else cout << iterator->second.second;


    });

}

string PhoneNumber::generatePhoneNumber(string &encoding) {
    boost::random::uniform_int_distribution<> operatorDistribution(1, 4);
    boost::random::uniform_int_distribution<> numberDistribution(0, 9);

    boost::random::uniform_int_distribution<> telenorPrefixDistribution(1, 5);
    boost::random::uniform_int_distribution<> ooredooPrefixDistribution(1, 3);
    boost::random::uniform_int_distribution<> MPTPrefixDistribution(1, 9);


    string result = "";
    int cacheNumber;
    string cacheString;

    for (int i = 0; i < 7; i++) {
        cacheNumber = numberDistribution(generatorObject);
        cacheString= to_string(cacheNumber);
        result+= cacheString;
        //result.push_back(cacheString.at(0));
    }




    switch (operatorDistribution(generatorObject)) {

        case 1: //MPT

            result="09"+this->mpt[MPTPrefixDistribution(generatorObject)].first + result;
            break;

        case 2: //Telenor
            result="09"+this->telenor[telenorPrefixDistribution(generatorObject)].first + result;
            break;


        case 3: //Ooredoo
            result="09"+this->ooredoo[ooredooPrefixDistribution(generatorObject)].first + result;
            break;

        case 4: //Mytel
            result="09"+this->mytel[0].first + result;
            break;
    }

    return result;

}
