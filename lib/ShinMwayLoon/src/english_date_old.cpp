//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#include "../include/english_date_old.h"
#include <map>
#include <iterator>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/date_time.hpp>
#include <regex>

typedef Xlotgative::ShinMwayLoon::EnglishDate XMwayLoon_EnglishDate;
namespace XMwayLoon =  Xlotgative::ShinMwayLoon;




XMwayLoon::ptr_string XMwayLoon_EnglishDate::convertEngDateToMyan(const std::string &engDate,const XMwayLoon::Encoding &encoding) {

    XMwayLoon::ptr_string result=std::make_unique<std::string> (engDate);
    XMwayLoon::ptr_string tempEngMonth=std::make_unique<std::string> ("");
    XMwayLoon::ptr_string tempEngDay=std::make_unique<std::string> ("");
    XMwayLoon::ptr_string tempEngYear=std::make_unique<std::string> ("");

    XMwayLoon::ptr_string tempMyanMonth=std::make_unique<std::string> ("");
    XMwayLoon::ptr_string tempMyanDay=std::make_unique<std::string> ("");
    XMwayLoon::ptr_string tempMyanYear=std::make_unique<std::string> ("");

    std::regex monthRegex("[A-Za-z]+");
    std::regex dayRegex("[0-9]{1,2}");
    std::regex yearRegex("[0-9]{4}");
    std::smatch matchingBehaviour;

    std::regex_search((*result), matchingBehaviour, monthRegex);
    for (auto element : matchingBehaviour) (*tempEngMonth)+=element;

    std::regex_search((*result), matchingBehaviour, dayRegex);
    for (auto element : matchingBehaviour) (*tempEngDay)+=element;

    std::regex_search((*result), matchingBehaviour, yearRegex);
    for (auto element : matchingBehaviour) (*tempEngYear)+=element;


    //return std::make_unique<std::string>(tempEngMonth) ;

   // std::cout<<std::endl<<(*tempEngMonth).size()<<std::endl;

    if((*tempEngMonth).size()==3)
        tempMyanMonth= XMwayLoon_EnglishDate::convertShortEngMonthToMyan((*tempEngMonth),encoding);
    else
        tempMyanMonth= XMwayLoon_EnglishDate::convertCompleteEngMonthToMyan((*tempEngMonth),encoding);


    //API is broken here
    *tempMyanDay="Myanmar";
    *tempMyanYear="Myanmar";


    boost::replace_all(*result,*tempEngMonth, *tempMyanMonth);
    boost::replace_all(*result,*tempEngYear, *tempMyanYear);
    boost::replace_all(*result,*tempEngDay, *tempMyanDay);

   // std::cout<<std::endl<<"Result : "<<(*result)<<std::endl;

    return result;
}

XMwayLoon::ptr_string XMwayLoon_EnglishDate::convertCompleteEngMonthToMyan(const std::string &engMonth,const XMwayLoon::Encoding &encoding) {
    std::string result;

    pcg objPCG(this->objRandomDevice);
    if (encoding == XMwayLoon::Encoding::Unicode) {
      //  cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
        result = this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
    } else if (encoding == XMwayLoon::Encoding::Zawgyi) {
       // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
        result =  this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;

    } else {
        std::uniform_int_distribution<> encodingDistribution(1, 2);
        pcg objPCG(this->objRandomDevice);
        int encoding = encodingDistribution(objPCG);
        if (encoding == 1) {
           // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
            result =   this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;


        } else {
           // cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
            result =  this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;

        }


    }
    return std::make_unique<std::string>(result);
}


XMwayLoon::ptr_string XMwayLoon_EnglishDate::convertShortEngMonthToMyan(const std::string &engMonth,const XMwayLoon::Encoding &encoding) {
    std::string result;

    if (encoding == XMwayLoon::Encoding::Unicode) {
        //  cout << this->myanMonths.get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
        result = this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
    } else if (encoding == XMwayLoon::Encoding::Zawgyi) {
        // cout << this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
        result =  this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;

    } else {
        std::uniform_int_distribution<> encodingDistribution(1, 2);
        pcg objPCG(this->objRandomDevice);
        int encoding = encodingDistribution(objPCG);
        if (encoding == 1) {
            // cout << this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
            result =   this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;


        } else {
            // cout << this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
            result =  this->myanMonths.get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;

        }


    }
    return std::make_unique<std::string>(result);
}

XMwayLoon::ptr_string XMwayLoon_EnglishDate::generateRandomEngDate(const std::string &format) {

    //TODO: windows implementation is needed
#ifdef _WIN32
    //linux code goes here
#else


#endif

    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    int currentYear = timeLocal.date().year();


    std::uniform_int_distribution<> febDistribution(1, 28);
    std::uniform_int_distribution<> thirdyOneDistribution(1, 31);
    std::uniform_int_distribution<> thirdyDistribution(1, 30);
    std::uniform_int_distribution<> monthDistribution(1, 12);
    std::uniform_int_distribution<> yearDistribution(currentYear - 20, currentYear);

    // c = (a>b) ? a : b;
    pcg objPCG(this->objRandomDevice);
    int month = monthDistribution(objPCG);
    int year = yearDistribution(objPCG);
    int days;

    switch (month) {

        case 2:
            days = febDistribution(objPCG);

            break;
        case 1:
        case 3:
        case 4:
        case 7:
        case 8:
        case 10:
        case 12: //31-day months
            days = thirdyOneDistribution(objPCG);

            break;

        case 5:
        case 6:
        case 9:
        case 11: //30-day months
            days = thirdyDistribution(objPCG);

            break;


    }


    boost::gregorian::date dateObj{year, month, days};
    std::stringstream stream  ;

    boost::gregorian::date_facet* facet(new boost::gregorian::date_facet(format.c_str()));
    stream.imbue(std::locale(std::cout.getloc(), facet));



    stream << dateObj;
    std::string dateString = stream.str();




    return std::make_unique<std::string>(dateString);


}

XMwayLoon::ptr_string XMwayLoon_EnglishDate::getRandomMyanDate(const std::string &format,const XMwayLoon::Encoding &encoding){

    XMwayLoon::ptr_string result=XMwayLoon_EnglishDate::generateRandomEngDate(format);
     result=XMwayLoon_EnglishDate::convertEngDateToMyan(*result,encoding);



    return result;
}



