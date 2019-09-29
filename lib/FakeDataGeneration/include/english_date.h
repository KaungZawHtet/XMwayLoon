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
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>


using namespace std;


using namespace boost::multi_index;
namespace Xlotgative{

    class EnglishDate{


        /*typedef multi_index_container<
                pair <string,string>,
                        indexed_by<
                                ordered_unique<identity<std::string>>,
                                ordered_unique<identity<std::string>>
                                >
                        > myanmarMonthContainer;
        myanmarMonthContainer myanmarMonths;*/

        std::map<string, pair <string,string>> myanmarMonths;
        std::map<pair <string,string>, pair <string,string>> englishMonths;
        std::map<std::string, pair <string,string>> myanmarNumbers;
//        std::map<std::string, pair <string,string>> myanmarDateKeywords;

    public:

        EnglishDate();
        std::map<std::string, pair <string,string>> getData();
        void convertEnglishNumberToMyanmar(std::string &,string&);
        std::string convertEnglishMonthToMyanmar(std::string &,string &);
        boost::gregorian::date generateRandomDate(std::string &);
        std::string convertEnglishDateToMyanmar(std::string &,string &);





    };






}










#endif //FAKEDATAGENERATOR_ENGLISH_DATE_H
