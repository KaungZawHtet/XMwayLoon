//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#ifndef FAKEDATAGENERATOR_ENGLISH_DATE_H
#define FAKEDATAGENERATOR_ENGLISH_DATE_H
#include <map>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/date_time.hpp>

namespace  Xlotgative
{


class EnglishDate{



public:
    std::map<std::string, std::string> myanmarDate;
    EnglishDate();
    void convertEnglishNumberToMyanmar(std::string &);
    void convertEnglishMonthToMyanmar(std::string &);
    boost::gregorian::date generateRandomDate(std::string &);

};

}

#endif //FAKEDATAGENERATOR_ENGLISH_DATE_H
