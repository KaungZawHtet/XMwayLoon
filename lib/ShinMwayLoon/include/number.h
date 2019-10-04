//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef SHINMWAYLOON_NUMBER_H
#define SHINMWAYLOON_NUMBER_H
#include <map>
#include "../include/global_objects.h"


namespace Xlotgative::ShinMwayLoon
{
    class Number
    {
        typedef std::map<std::string, std::string> type_myanNum;
        std::unique_ptr<type_myanNum> myanNum;

    public:
        Xlotgative::ShinMwayLoon::ptr_string convertEngNumToMyan(const std::string &engNum);
        Xlotgative::ShinMwayLoon::ptr_string getRandomMyanNum( const unsigned long max);
        Number();

    };
}

#endif //SHINMWAYLOON_NUMBER_H
