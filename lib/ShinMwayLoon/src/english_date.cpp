//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#include "../include/english_date.h"
#include "../include/global_objects.h"
#include <map>
#include <string>
#include <iterator>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/date_time.hpp>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <regex>

typedef Xlotgative::ShinMwayLoon::EnglishDate XMwayLoon_EnglishDate;
namespace XMwayLoon =  Xlotgative::ShinMwayLoon;
XMwayLoon_EnglishDate::EnglishDate() {




    myanMonths= std::make_unique<myanMonthsContainer>();

    typedef std::pair<std::string, std::string> pair_string;





    this->myanMonths->insert(Month("Jan", "January", "ဇန်နဝါရီ", "ဇန္နဝါရီ"));
    this->myanMonths->insert(Month("Feb", "February", "ဖေဖော်ဝါရီ", "ေဖေဖာ္ဝါရီ"));
    this->myanMonths->insert(Month("Mar", "March", "မတ်", "မတ္"));
    this->myanMonths->insert(Month("Apr", "April", "ဧပရယ်", "ဧပရယ္"));
    this->myanMonths->insert(Month("May", "May", "မေ", "ေမ"));
    this->myanMonths->insert(Month("Jun", "June", "ဇွန်", "ဇြန္"));
    this->myanMonths->insert(Month("Jul", "July", "ဇူလိုင်", "ဇူလိုင္"));
    this->myanMonths->insert(Month("Aug", "August", "ဩဂုတ်", "ဩဂုတ္"));
    this->myanMonths->insert(Month("Sept", "September", "စက်တင်ဘာ", "စက္တင္ဘာ"));
    this->myanMonths->insert(Month("Oct", "October", "အောက်တိုဘာ", "ေအာက္တိုဘာ"));
    this->myanMonths->insert(Month("Nov", "November", "နိုဝင်ဘာ", "ႏိုဝင္ဘာ"));
    this->myanMonths->insert(Month("Dec", "December", "ဒီဇင်ဘာ", "ဒီဇင္ဘာ"));


}



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

    tempMyanDay=obj_number.convertEngNumToMyan(*tempEngDay);
    tempMyanYear=obj_number.convertEngNumToMyan(*tempEngYear);


    boost::replace_all(*result,*tempEngMonth, *tempMyanMonth);
    boost::replace_all(*result,*tempEngYear, *tempMyanYear);
    boost::replace_all(*result,*tempEngDay, *tempMyanDay);

   // std::cout<<std::endl<<"Result : "<<(*result)<<std::endl;





    return result;


}

XMwayLoon::ptr_string XMwayLoon_EnglishDate::convertCompleteEngMonthToMyan(const std::string &engMonth,const XMwayLoon::Encoding &encoding) {
    std::string result;



    if (encoding == XMwayLoon::Encoding::Unicode) {
      //  cout << this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
        result = this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
    } else if (encoding == XMwayLoon::Encoding::Zawgyi) {
       // cout << this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
        result =  this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;

    } else {
        boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
        int encoding = encodingDistribution(generatorObject);
        if (encoding == 1) {
           // cout << this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
            result =   this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;


        } else {
           // cout << this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;
            result =  this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->zawgyiMyanMonth;

        }


    }
    return std::make_unique<std::string>(result);
}


XMwayLoon::ptr_string XMwayLoon_EnglishDate::convertShortEngMonthToMyan(const std::string &engMonth,const XMwayLoon::Encoding &encoding) {
    std::string result;

    if (encoding == XMwayLoon::Encoding::Unicode) {
        //  cout << this->myanMonths->get<XMwayLoon::tag::completeEngMonth>().find(engMonth)->unicodeMyanMonth;
        result = this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
    } else if (encoding == XMwayLoon::Encoding::Zawgyi) {
        // cout << this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
        result =  this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;

    } else {
        boost::random::uniform_int_distribution<> encodingDistribution(1, 2);
        int encoding = encodingDistribution(generatorObject);
        if (encoding == 1) {
            // cout << this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;
            result =   this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->unicodeMyanMonth;


        } else {
            // cout << this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;
            result =  this->myanMonths->get<XMwayLoon::tag::shortEngMonth>().find(engMonth)->zawgyiMyanMonth;

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
    std::string dateString = stream.str();




    return std::make_unique<std::string>(dateString);


}

XMwayLoon::ptr_string XMwayLoon_EnglishDate::getRandomMyanDate(const std::string &format,const XMwayLoon::Encoding &encoding){

    XMwayLoon::ptr_string result=XMwayLoon_EnglishDate::generateRandomEngDate(format);
     result=XMwayLoon_EnglishDate::convertEngDateToMyan(*result,encoding);



    return result;
}



