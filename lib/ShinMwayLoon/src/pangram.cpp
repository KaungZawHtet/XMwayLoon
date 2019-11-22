//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#include "../include/pangram.h"
#include <iostream>
#include "../include/global_objects.h"

typedef Xlotgative::ShinMwayLoon::Pangram XMwayLoon_Pangram;
namespace XMwayLoon =  Xlotgative::ShinMwayLoon;


std::string XMwayLoon_Pangram::getPangram(XMwayLoon::Encoding encoding){


    return [&]() {
        switch (encoding) {
            case XMwayLoon::Encoding::Unicode:
                return this->myanPangram.first;
            case XMwayLoon::Encoding::Zawgyi:
                return this->myanPangram.second;
            default :
                boost::random::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(generatorObject)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanPangram.first;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanPangram.second;
                }
        }
    }();


}