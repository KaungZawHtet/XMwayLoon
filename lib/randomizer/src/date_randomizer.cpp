//
// Created by Kaung Zaw Htet on 2019-11-13.
//

#include <randomizer/date_randomizer.h>
#include <regex>
#include <randomizer/typedef.h>


std::string XMwayLoon_DateRandomizer::convertCompleteEngMonthToMyan
        (const std::string engMonth, const XML_RE::Encoding &encoding) {
    return [&]() {
    
        switch (encoding) {
            case XML_RE::Encoding::unicode:
                return this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
            case XML_RE::Encoding::zawgyi:
                return this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                }
        }
    }();
}

std::string XMwayLoon_DateRandomizer::convertShortEngMonthToMyan
        (const std::string engMonth, const XML_RE::Encoding &encoding) {
    return [&]() {
        
        switch (encoding) {
            case XML_RE::Encoding::unicode:
                return this->myanMonths.get<XMwayLoon::Randomizer::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
            case XML_RE::Encoding::zawgyi:
                return this->myanMonths.get<XMwayLoon::Randomizer::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
            default :
                std::uniform_int_distribution<> encodingDistribution(0, 1);
                if (encodingDistribution(this->objPCG)) {
                    // cout << this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
                    return this->myanMonths.get<XMwayLoon::Randomizer::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
                } else {
                    // cout << this->myanMonths.get<XMwayLoon::Randomizer::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
                    return this->myanMonths.get<XMwayLoon::Randomizer::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
                }
        }
    }();
}

std::string XMwayLoon_DateRandomizer::generateRandomEngDate
        (const std::string &format) {
    //TODO: windows implementation is needed
#ifdef _WIN32

#else
//linux code goes here

    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    int currentYear = timeLocal.date().year();
#endif
    std::uniform_int_distribution<> febDistribution(1, 28);
    std::uniform_int_distribution<> thirdyOneDistribution(1, 31);
    std::uniform_int_distribution<> thirdyDistribution(1, 30);
    std::uniform_int_distribution<> monthDistribution(1, 12);
    std::uniform_int_distribution<> yearDistribution(currentYear - 20, currentYear);
    // c = (a>b) ? a : b;

    
    int month = monthDistribution(this->objPCG);
    int year = yearDistribution(this->objPCG);
    int days;
    switch (month) {
        case 2:
            days = febDistribution(this->objPCG);
            break;

        case 1:
        case 3:
        case 4:
        case 7:
        case 8:
        case 10:
        case 12: //31-day months
            days = thirdyOneDistribution(this->objPCG);
            break;

        case 5:
        case 6:
        case 9:
        case 11: //30-day months
            days = thirdyDistribution(this->objPCG);
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

std::string XMwayLoon_DateRandomizer::convertEngDateToMyan
(std::string engDate, const XML_RE::Encoding &encoding){


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
            return XMwayLoon_DateRandomizer::convertShortEngMonthToMyan((tempEngMonth),encoding);
        else
            return XMwayLoon_DateRandomizer::convertCompleteEngMonthToMyan((tempEngMonth),encoding);

    }();

    std::string tempMyanDay=this->objNumberRandomizer.convertEngNumToMyan(tempEngDay);
    std::string tempMyanYear=this->objNumberRandomizer.convertEngNumToMyan(tempEngYear);


    //engDate now become MyanDate from now on
    boost::replace_all(engDate,tempEngMonth, tempMyanMonth);
    boost::replace_all(engDate,tempEngYear, tempMyanYear);
    boost::replace_all(engDate,tempEngDay, tempMyanDay);

    return engDate;

}

std::string XMwayLoon_DateRandomizer::getRandomMyanDate
(const std::string &format,const XML_RE::Encoding &encoding){

    return XMwayLoon_DateRandomizer::convertEngDateToMyan(
            XMwayLoon_DateRandomizer::generateRandomEngDate(format),encoding);
}
XMwayLoon_DateRandomizer::DateRandomizer() {
    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);
}

XMwayLoon_DateRandomizer::DateRandomizer(DateType tmp_dateType)
: objDateType(std::move(tmp_dateType))
{
    std::random_device objRandomDevice;
    this->objPCG.seed(objRandomDevice);

}

