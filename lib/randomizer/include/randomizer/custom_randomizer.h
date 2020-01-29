//
// Created by Kaung Zaw Htet on 2020-01-30.
//

#ifndef XMWAYLOON_CUSTOM_RANDOMIZER_H
#define XMWAYLOON_CUSTOM_RANDOMIZER_H

#include "global_objects.h"

namespace XMwayLoon::Randomizer {
    class CustomRandomizer {

    private:
        std::vector<std::string> vecUniRecords;
        std::vector<std::string> vecZgRecords;
        pcg objPCG;
        XMwayLoon::Randomizer::Encoding encoding;

    public:

         CustomRandomizer(std::string typeName,XMwayLoon::Randomizer::Encoding tmp_encoding=XMwayLoon::Randomizer::Encoding::unicode);

        std::string getRandomData();
    };


}
#endif //XMWAYLOON_CUSTOM_RANDOMIZER_H
