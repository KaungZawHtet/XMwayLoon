//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#include <ShinMwayLoon/pangram_randomizer.h>
#include <iostream>
#include <ShinMwayLoon/global_objects.h>

typedef Xlotgative::ShinMwayLoon::PangramRandomizer XMwayLoon_PangramRandomizer;



std::string XMwayLoon_PangramRandomizer::getPangram(XMwayLoon::Encoding encoding){


    return [&]() {
      
        switch (encoding) {
            case XMwayLoon::Encoding::unicode:
                return this->myanPangram.first;
            case XMwayLoon::Encoding::zawgyi:
                return this->myanPangram.second;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanPangram.first;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanPangram.second;
                }
        }
    }();


}

Xlotgative::ShinMwayLoon::PangramRandomizer::PangramRandomizer() {
    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);

}
