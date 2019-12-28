//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#include <ShinMwayLoon/ph_number_randomizer.h>
#include <regex>



typedef XMwayLoon::PhoneNumberRandomizer XMwayLoon_PhoneNumberRandomizerRandomizer;



std::string XMwayLoon_PhoneNumberRandomizerRandomizer::generateEngPhNum(CountryCodeFlag countryCodeSwitch) {
    std::uniform_int_distribution<> operatorDistribution(1, 4);
    std::uniform_int_distribution<> numDistribution(1000000, 9999999);
    pcg objPCG(this->objRandomDevice);
    std::string result = std::to_string(numDistribution(objPCG));
        switch (operatorDistribution(objPCG)) {

            case 1: //MPT
            {
                std::uniform_int_distribution<> MPTPrefixDistribution(0, 9);
                result = "09" + this->mpt.operator[](MPTPrefixDistribution(objPCG)).first + result;
            }
                break;

            case 2: //Telenor
            {
                std::uniform_int_distribution<> telenorPrefixDistribution(0, 4);
                result = "09" + this->telenor.operator[](telenorPrefixDistribution(objPCG)).first + result;
            }
                break;
            case 3: //Ooredoo

            {
                std::uniform_int_distribution<> ooredooPrefixDistribution(0, 2);
                result = "09" + this->ooredoo.operator[](ooredooPrefixDistribution(objPCG)).first + result;
            }
                 break;

            case 4: //Mytel

                result = "09" + this->mytel.operator[](0).first + result;
                break;
        }

        switch (countryCodeSwitch) {
            case PhoneNumberRandomizer::CountryCodeFlag::withCountryCode :
                result = "+95" + result;
                // std::cout<<endl<<result<<endl;
                break;
            case PhoneNumberRandomizer::CountryCodeFlag::noCountryCode :
                break;
            case PhoneNumberRandomizer::CountryCodeFlag::random :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(objPCG)) result = "+95" + result;
                break;
        }
    return result;
}


std::string XMwayLoon_PhoneNumberRandomizerRandomizer::getRandomMyanPhNum
(const XMwayLoon_PhoneNumberRandomizerRandomizer::CountryCodeFlag countryCodeSwitch) {
    return this->objNumberRandomizer.convertEngNumToMyan(this->generateEngPhNum(countryCodeSwitch));

}
