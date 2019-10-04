//
// Created by Kaung Zaw Htet on 2019-10-04.
//

#ifndef SHINMWAYLOON_PANGRAM_H
#define SHINMWAYLOON_PANGRAM_H

#include <map>
#include "global_objects.h"

namespace Xlotgative::ShinMwayLoon
{
    class Pangram
    {
        std::pair<std::string,std::string> myanPangram;

    public:
        Pangram();
        Xlotgative::ShinMwayLoon::ptr_string getPangram(Xlotgative::ShinMwayLoon::Encoding encoding);


    };
}

#endif //SHINMWAYLOON_PANGRAM_H
