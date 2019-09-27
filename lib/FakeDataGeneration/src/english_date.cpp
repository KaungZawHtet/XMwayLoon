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
using namespace std;
using namespace Xlotgative;

EnglishDate::EnglishDate() {


    this->myanmarDateKeywords["0"]=pair<string,string>("၀","၀");
    this->myanmarDateKeywords["1"]=pair<string,string>("၁","၁");
    this->myanmarDateKeywords["2"]=pair<string,string>("၂","၂");
    this->myanmarDateKeywords["3"]=pair<string,string>("၃","၃");
    this->myanmarDateKeywords["4"]=pair<string,string>("၄","၄");
    this->myanmarDateKeywords["5"]=pair<string,string>("၅","၅");
    this->myanmarDateKeywords["6"]=pair<string,string>("၆","၆");
    this->myanmarDateKeywords["7"]=pair<string,string>("၇","၇");
    this->myanmarDateKeywords["8"]=pair<string,string>("၈","၈");
    this->myanmarDateKeywords["9"]=pair<string,string>("၉","၉");

    this->myanmarDateKeywords["January"]=pair<string,string>("ဇန်နဝါရီ","ဇန္နဝါရီ");
    this->myanmarDateKeywords["February"]=pair<string,string>("ဖေဖော်ဝါရီ","ေဖေဖာ္ဝါရီ");
    this->myanmarDateKeywords["March"]=pair<string,string>("မတ်","မတ္");
    this->myanmarDateKeywords["April"]=pair<string,string>("ဧပရယ်","ဧပရယ္");
    this->myanmarDateKeywords["May"]=pair<string,string>("မေ","ေမ");
    this->myanmarDateKeywords["June"]=pair<string,string>("ဇွန်","ဇြန္");
    this->myanmarDateKeywords["July"]=pair<string,string>("ဇူလိုင်","ဇူလိုင္");
    this->myanmarDateKeywords["August"]=pair<string,string>("ဩဂုတ်","ဩဂုတ္");
    this->myanmarDateKeywords["September"]=pair<string,string>("စက်တင်ဘာ","စက္တင္ဘာ");
    this->myanmarDateKeywords["October"]=pair<string,string>("အောက်တိုဘာ","ေအာက္တိုဘာ");
    this->myanmarDateKeywords["November"]=pair<string,string>("နိုဝင်ဘာ","ႏိုဝင္ဘာ");
    this->myanmarDateKeywords["December"]=pair<string,string>("ဒီဇင်ဘာ","ဒီဇင္ဘာ");


}

 void EnglishDate::convertEnglishNumberToMyanmar(string & englishNumber,string &encoding){

    string result;

    std::for_each(englishNumber.begin(),englishNumber.end(),[this,encoding](auto &englishCharacter){

        string stringCache;
        stringCache.push_back(englishCharacter);
        auto iterator=  this->myanmarDateKeywords.find(stringCache);

        if(encoding == UNICODE )cout << iterator->second.first;
        else  cout << iterator->second.second;


    });


}

void EnglishDate::convertEnglishMonthToMyanmar(string & englishMonth,string &encoding)
{
    std::map<string,pair<string,string>>::iterator iterator= this->myanmarDateKeywords.find(englishMonth);

    if(encoding == UNICODE )cout << iterator->second.first;
    else  cout << iterator->second.second;
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

    boost::gregorian::date dateObj { 11, 2, 3 };


    return dateObj;


}

std::map<std::string, pair <string,string>> EnglishDate::getData(){

    return this->myanmarDateKeywords;
}

template<class Archive>
void EnglishDate::serialize(Archive &archieve, const unsigned int version){
    archieve & myanmarDateKeywords;
}


/*void EnglishDate::saveMyanmarKeywords(const std::string & filename){
    // make an archive
    std::ofstream outputFileStream(filename);
    boost::archive::text_oarchive outputArchieve(outputFileStream);
    outputArchieve << this->myanmarDateKeywords;



}*/


    void EnglishDate::restoreMyanmarKeywords(const char * filename){



        /*// open the archive
        std::ifstream inputFileStream(filename, std::ios::binary);
        std::ifstream a("good.bin", std::ios::binary);
        boost::archive::text_iarchive inputArchieve();*/

    {
        std::ifstream ifs("file.txt");


        boost::archive::text_iarchive iar(ifs); // no exception!
        ifs.close();

    }

    // restore the schedule from the archive
      //  inputArchieve >> this->myanmarDateKeywords;

    }



