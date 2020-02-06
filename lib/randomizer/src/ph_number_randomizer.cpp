//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#include <randomizer/ph_number_randomizer.h>
#include <regex>
#include <randomizer/typedef.h>



//TODO:: This need to break
std::string XMwayLoon_PhoneNumberRandomizer::generateEngPhNum(XML_RE::CountryCodeFlag countryCodeSwitch) {
    std::uniform_int_distribution<> operatorDistribution(1, 4);
    std::uniform_int_distribution<> numDistribution(1000000, 9999999);

    std::string result = std::to_string(numDistribution(this->objPCG));
        switch (operatorDistribution(this->objPCG)) {

            case 1: //MPT
            {
                std::uniform_int_distribution<> MPTPrefixDistribution(0, 9);
                result = "09" + this->mpt.operator[](MPTPrefixDistribution(this->objPCG)).first + result;
            }
                break;

            case 2: //Telenor
            {
                std::uniform_int_distribution<> telenorPrefixDistribution(0, 4);
                result = "09" + this->telenor.operator[](telenorPrefixDistribution(this->objPCG)).first + result;
            }
                break;
            case 3: //Ooredoo

            {
                std::uniform_int_distribution<> ooredooPrefixDistribution(0, 2);
                result = "09" + this->ooredoo.operator[](ooredooPrefixDistribution(this->objPCG)).first + result;
            }
                 break;

            case 4: //Mytel

                result = "09" + this->mytel.operator[](0).first + result;
                break;
        }

        switch (countryCodeSwitch) {
            case XML_RE::CountryCodeFlag::withCountryCode :
                result = "+95" + result;
                // std::cout<<endl<<result<<endl;
                break;
            case XML_RE::CountryCodeFlag::noCountryCode :
                break;
            case XML_RE::CountryCodeFlag::random :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) result = "+95" + result;
                break;
        }
    return result;
}


std::string XMwayLoon_PhoneNumberRandomizer::getRandomMyanPhNum
(const XML_RE::CountryCodeFlag countryCodeSwitch) {
    return this->objNumberRandomizer.convertEngNumToMyan(this->generateEngPhNum(countryCodeSwitch));

}

XMwayLoon_PhoneNumberRandomizer::PhoneNumberRandomizer() {

  this->load();

}

std::string XMwayLoon_PhoneNumberRandomizer::getRandom() {
    return this->getRandomMyanPhNum(objPhNumberType.countryCode);
}

void XMwayLoon_PhoneNumberRandomizer::load() {
    std::random_device objRD;
    this->objPCG.seed( objRD);
}

XMwayLoon_PhoneNumberRandomizer::PhoneNumberRandomizer(PhNumberType tmp_objPhNumberType) 
: objPhNumberType(std::move(tmp_objPhNumberType))
{
this->load();
}

