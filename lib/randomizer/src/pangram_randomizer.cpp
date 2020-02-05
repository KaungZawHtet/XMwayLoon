//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#include <randomizer/pangram_randomizer.h>
#include <iostream>
#include <randomizer/typedef.h>





std::string XMwayLoon_PangramRandomizer::getPangram(XML_RE::Encoding encoding){


    return [&]() {
      
        switch (encoding) {
            case XML_RE::Encoding::unicode:
                return this->myanPangram.first.data();
            case XML_RE::Encoding::zawgyi:
                return this->myanPangram.second.data();
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanPangram.first.data();
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanPangram.second.data();
                }
        }
    }();


}

XMwayLoon_PangramRandomizer::PangramRandomizer() {
    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);

}
