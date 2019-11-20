//
// Created by Kaung Zaw Htet on 2019-11-13.
//

#include "../include/date.h"
#include "../include/global_objects.h"
#include <regex>

typedef Xlotgative::ShinMwayLoon::Date XMwayLoon_Date;
namespace XMwayLoon =  Xlotgative::ShinMwayLoon;

std::string XMwayLoon_Date::convertCompleteEngMonthToMyan
        (const std::string engMonth, const XMwayLoon::Encoding &encoding) {
    return [&]() {
        switch (encoding) {
            case XMwayLoon::Encoding::Unicode:
                return this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
            case XMwayLoon::Encoding::Zawgyi:
                return this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
            default :
                boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
                int encoding = encodingDistribution(generatorObject);
                if (encoding == 1) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                }
        }
    }();
}

std::string XMwayLoon_Date::convertShortEngMonthToMyan
        (const std::string engMonth, const XMwayLoon::Encoding &encoding) {
    return [&]() {
        switch (encoding) {
            case XMwayLoon::Encoding::Unicode:
                return this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
            case XMwayLoon::Encoding::Zawgyi:
                return this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
            default :
                boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
                int encoding = encodingDistribution(generatorObject);
                if (encoding == 1) {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
                }
        }
    }();
}

std::string XMwayLoon_Date::generateRandomEngDate
        (const std::string &format) {
    //TODO: windows implementation is needed
#ifdef _WIN32

#else
//linux code goes here

    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    int currentYear = timeLocal.date().year();
#endif
    boost::random::uniform_int_distribution<> febDistribution(1, 28);
    boost::random::uniform_int_distribution<> thirdyOneDistribution(1, 31);
    boost::random::uniform_int_distribution<> thirdyDistribution(1, 30);
    boost::random::uniform_int_distribution<> monthDistribution(1, 12);
    boost::random::uniform_int_distribution<> yearDistribution(currentYear - 20, currentYear);
    // c = (a>b) ? a : b;
    int month = monthDistribution(generatorObject);
    int year = yearDistribution(generatorObject);
    int days;
    switch (month) {
        case 2:
            days = febDistribution(generatorObject);
            break;

        case 1:
        case 3:
        case 4:
        case 7:
        case 8:
        case 10:
        case 12: //31-day months
            days = thirdyOneDistribution(generatorObject);
            break;

        case 5:
        case 6:
        case 9:
        case 11: //30-day months
            days = thirdyDistribution(generatorObject);
            break;
    }
    boost::gregorian::date dateObj{year, month, days};
    std::stringstream stream  ;
    boost::gregorian::date_facet* facet(new boost::gregorian::date_facet(format.c_str()));
    stream.imbue(std::locale(std::cout.getloc(), facet));
    stream << dateObj;
   // std::string dateString = stream.str();
    return stream.str();
}

std::string XMwayLoon_Date::convertEngDateToMyan
(std::string engDate, const Xlotgative::ShinMwayLoon::Encoding &encoding){


    std::smatch matchingBehaviour;

    std::string tempEngMonth{};
    std::regex monthRegex("[A-Za-z]+");
    std::regex_search((engDate), matchingBehaviour, monthRegex);
    for (auto element : matchingBehaviour) tempEngMonth+=element;

    std::string tempEngDay{};
    std::regex dayRegex("[0-9]{1,2}");
    std::regex_search((engDate), matchingBehaviour, dayRegex);
    for (auto element : matchingBehaviour) tempEngDay+=element;

    std::string tempEngYear{};
    std::regex yearRegex("[0-9]{4}");
    std::regex_search((engDate), matchingBehaviour, yearRegex);
    for (auto element : matchingBehaviour) tempEngYear+=element;


    std::string tempMyanMonth = [&](){
        if((tempEngMonth).size()==3)
            return XMwayLoon_Date::convertShortEngMonthToMyan((tempEngMonth),encoding);
        else
            return XMwayLoon_Date::convertCompleteEngMonthToMyan((tempEngMonth),encoding);

    }();

    std::string tempMyanDay=this->xNumber.convertEngNumToMyan(tempEngDay);
    std::string tempMyanYear=this->xNumber.convertEngNumToMyan(tempEngYear);


    //engDate now become MyanDate from now on
    boost::replace_all(engDate,tempEngMonth, tempMyanMonth);
    boost::replace_all(engDate,tempEngYear, tempMyanYear);
    boost::replace_all(engDate,tempEngDay, tempMyanDay);

    return engDate;

}

std::string XMwayLoon_Date::getRandomMyanDate
(const std::string &format,const Xlotgative::ShinMwayLoon::Encoding &encoding){

    return XMwayLoon_Date::convertEngDateToMyan(
            XMwayLoon_Date::generateRandomEngDate(format),encoding);
}
