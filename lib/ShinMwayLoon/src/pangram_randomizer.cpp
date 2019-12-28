//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#include <ShinMwayLoon/pangram_randomizer.h>
#include <iostream>
#include <ShinMwayLoon/global_objects.h>

typedef Xlotgative::ShinMwayLoon::PangramRandomizer XMwayLoon_PangramRandomizer;



std::string XMwayLoon_PangramRandomizer::getPangram(XMwayLoon::Encoding encoding){


    return [&]() {
        pcg objPCG(this->objRandomDevice);
        switch (encoding) {
            case XMwayLoon::Encoding::Unicode:
                return this->myanPangram.first;
            case XMwayLoon::Encoding::Zawgyi:
                return this->myanPangram.second;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanPangram.first;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanPangram.second;
                }
        }
    }();


}