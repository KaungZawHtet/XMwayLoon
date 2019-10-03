//
// Created by Kaung Zaw Htet on 2019-10-03.
//

#ifndef FAKEDATAGENERATOR_NUMBER_H
#define FAKEDATAGENERATOR_NUMBER_H
#include <map>
#include "../include/global_objects.h"


namespace Xlotgative
{
    class Number
    {
        typedef std::map<std::string, std::string> type_myanNum;
        std::unique_ptr<type_myanNum> myanNum;

    public:
        Xlotgative::ptr_string convertEngNumToMyan(const std::string &engNum);
        Number();

    };
}

#endif //FAKEDATAGENERATOR_NUMBER_H
