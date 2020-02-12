//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#ifndef XMWAYLOON_PH_NUMBER_H
#define XMWAYLOON_PH_NUMBER_H

#include <model/type/enums.h>
#include <randomizer/faster_random.h>
#include <randomizer/number_randomizer.h>
namespace XMwayLoon::Randomizer {
    class PhoneNumber : public Randomizer::RootRandomizer
            {

    protected:
        pcg objPCG;
    public:


        std::array<std::string, 3> prefix = {"၀၉", "+၉၅၉", "၉၅၉"};
        XML_RE::CountryCodeFlag ccFlag;
        NumberRandomizer objNumRandomizer;
        void load() override ;

        PhoneNumber(XML_RE::CountryCodeFlag tmp_ccFlag);

        std::string getPrefix();



    };

}
#endif //XMWAYLOON_PH_NUMBER_H
