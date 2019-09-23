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
using namespace std;
using namespace Xlotgative;

EnglishDate::EnglishDate() {


    this->myanmarDate["0"]="၀";
    this->myanmarDate["1"]="၁";
    this->myanmarDate["2"]="၂";
    this->myanmarDate["3"]="၃";
    this->myanmarDate["4"]="၄";
    this->myanmarDate["5"]="၅";
    this->myanmarDate["6"]="၆";
    this->myanmarDate["7"]="၇";
    this->myanmarDate["8"]="၈";
    this->myanmarDate["9"]="၉";

    this->myanmarDate["January"]="ဇန်နဝါရီ";
    this->myanmarDate["February"]="ဖေဖဝါရီ";
    this->myanmarDate["March"]="မတ်";
    this->myanmarDate["April"]="ဧပရယ်";
    this->myanmarDate["May"]="မေ";
    this->myanmarDate["June"]="ဂျွန်";
    this->myanmarDate["July"]="ဂျူလိုင်";
    this->myanmarDate["August"]="ဩဂုတ်";
    this->myanmarDate["September"]="စက်တင်ဘာ";
    this->myanmarDate["October"]="အောက်တိုဘာ";
    this->myanmarDate["November"]="နိုဝင်ဘာ";
    this->myanmarDate["December"]="ဒီဇင်ဘာ";




    /*this->myanmarDate.insert(pair<string,string>("January", "ဇန်နဝါရီ"));
    this->myanmarDate.insert(pair<string,string>("February", "ဖေဖဝါရီ"));
    this->myanmarDate.insert(pair<string,string>("March", "မတ်"));
    this->myanmarDate.insert(pair<string,string>("April", "ဧပရယ်"));
    this->myanmarDate.insert(pair<string,string>("May", "မေ"));
    this->myanmarDate.insert(pair<string,string>("June", "ဂျွန်"));
    this->myanmarDate.insert(pair<string,string>("July", "ဂျူလိုင်"));
    this->myanmarDate.insert(pair<string,string>("August", "ဩဂုတ်"));
    this->myanmarDate.insert(pair<string,string>("September", "စက်တင်ဘာ"));
    this->myanmarDate.insert(pair<string,string>("October", "အောက်တိုဘာ"));
    this->myanmarDate.insert(pair<string,string>("November", "နိုဝင်ဘာ"));
    this->myanmarDate.insert(pair<string,string>("December", "ဒီဇင်ဘာ"));
    this->myanmarDate.insert(pair<string,string>("0", "၀"));
    this->myanmarDate.insert(pair<string,string>("1", "၁"));
    this->myanmarDate.insert(pair<string,string>("2", "၂"));
    this->myanmarDate.insert(pair<string,string>("3", "၃"));
    this->myanmarDate.insert(pair<string,string>("4", "၄"));
    this->myanmarDate.insert(pair<string,string>("5", "၅"));
    this->myanmarDate.insert(pair<string,string>("6", "၆"));
    this->myanmarDate.insert(pair<string,string>("7", "၇"));
    this->myanmarDate.insert(pair<string,string>("8", "၈"));
    this->myanmarDate.insert(pair<string,string>("9", "၉"));*/

}

 void EnglishDate::convertEnglishNumberToMyanmar(std::string & englishNumber){

    string result;

    std::for_each(englishNumber.begin(),englishNumber.end(),[this](auto &englishCharacter){

        string stringCache;
        stringCache.push_back(englishCharacter);
        std::map<string,string>::iterator iterator=  this->myanmarDate.find(stringCache);

       cout<< iterator->second;


    });


}

void EnglishDate::convertEnglishMonthToMyanmar(std::string & englishMonth)
{
    std::map<string,string>::iterator iterator= this->myanmarDate.find(englishMonth);

    cout << iterator->second;
}

boost::gregorian::date EnglishDate::generateRandomDate(std::string &format)
{

    //TODO: windows implementation is needed
#ifdef _WIN32
    //linux code goes here
#else



#endif

    boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();
    int currentYear= timeLocal.date().year();


    boost::random::uniform_int_distribution<> febDistribution(1, 28);
    boost::random::uniform_int_distribution<> thirdyOneDistribution(1, 31);
    boost::random::uniform_int_distribution<> thirdyDistribution(1, 30);
    boost::random::uniform_int_distribution<> monthDistribution(1, 12);
    boost::random::uniform_int_distribution<> yearDistribution(currentYear-20, currentYear);

    // c = (a>b) ? a : b;
    int month=monthDistribution(generatorObject);
    int year=yearDistribution(generatorObject);
    int days;

    switch (month){

        case 2:
             days=febDistribution(generatorObject);

            break;
        case 1: case 3: case 4: case 7:case 8:case 10: case 12: //31-day months
             days=thirdyOneDistribution(generatorObject);

            break;

        case 5: case 6:case 9:case 11: //30-day months
             days=thirdyDistribution(generatorObject);

            break;


    }

    boost::gregorian::date dateObj { year, month, days };


    return dateObj;


}