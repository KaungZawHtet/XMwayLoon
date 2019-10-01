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
#include "global_objects.h"


#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>





namespace Xlotgative{

    namespace tag {
        struct shortEngMonth;
        struct completeEngMonth;
        struct unicodeMyanMonth;
        struct zawgyiMyanMonth;
    }



    class EnglishDate{

        typedef std::map<std::pair <std::string,std::string>, std::pair <std::string,std::string>> type_englishMonths;
        typedef std::map<std::string, std::pair <std::string,std::string>> type_myanNumbers;



        struct Month
        {


            std::string shortEngMonth;
            std::string completeEngMonth;
            std::string unicodeMyanMonth;
            std::string zawgyiMyanMonth;

            Month(std::string tempshortEngMonth,std::string tempCompleteEngMonth,
                  std::string tempUnicodeMyanMonth, std::string tempZawgyiMyanMonth)
                    : shortEngMonth(tempshortEngMonth),
                      completeEngMonth(tempCompleteEngMonth),
                      unicodeMyanMonth(tempUnicodeMyanMonth),
                      zawgyiMyanMonth(tempZawgyiMyanMonth)
                    {}

        };

        typedef boost::multi_index::multi_index_container<
                Month,
                boost::multi_index::indexed_by<
                        boost::multi_index::ordered_unique<
                                boost::multi_index::tag<tag::shortEngMonth>,
                                boost::multi_index::member<Month, std::string, &Month::shortEngMonth>>,
                        boost::multi_index::ordered_unique<
                                boost::multi_index::tag<tag::completeEngMonth>,
                                boost::multi_index::member<Month, std::string, &Month::completeEngMonth>>

                >> myanMonthsContainer;


        std::unique_ptr<myanMonthsContainer> myanMonths;
        std::unique_ptr<type_englishMonths> englishMonths;
        std::unique_ptr<type_myanNumbers> myanNumbers;
//        std::map<std::string, pair <string,string>> myanDateKeywords;

    public:

        EnglishDate();
        ptr_string convertEngNumberToMyan(std::string &,const std::string &encoding);
        ptr_string convertCompleteEngMonthToMyan(const std::string &,const std::string &encoding);
        ptr_string convertShortEngMonthToMyan(const std::string &,const std::string &encoding);
        ptr_string generateRandomEngDate(const std::string &encoding);
        ptr_string convertEngDateToMyan(const std::string &, const std::string &encoding);
        ptr_string getRandomMyanDate(const std::string &format,const std::string &encoding);
/*
        std::unique_ptr<myanMonthsContainer> getMonths();
        std::unique_ptr<type_myanNumbers> getNumbers();*/





    };






}










#endif //FAKEDATAGENERATOR_ENGLISH_DATE_H
