//
// Created by Kaung Zaw Htet on 2019-11-13.
//

#ifndef FAKEDATAGENERATOR_DATE_H
#define FAKEDATAGENERATOR_DATE_H
#include "faster_random.h"
#include <map>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/date_time.hpp>
#include <model/type/enums.h>
#include <randomizer/number_randomizer.h>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <randomizer/faster_random.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>





namespace XMwayLoon::Randomizer{

    namespace tag {
        struct shortEngMonth;
        struct completeEngMonth;
        struct unicodeMyanMonth;
        struct zawgyiMyanMonth;
    }

    class DateRandomizer{


        struct Month
        {
             std::string shortEngMonth;
             std::string completeEngMonth;
             std::string unicodeMyanMonth;
             std::string zawgyiMyanMonth;

            Month(std::string tempShortEngMonth,std::string tempCompleteEngMonth,
                  std::string tempUnicodeMyanMonth, std::string tempZawgyiMyanMonth)
                    : shortEngMonth(std::move(tempShortEngMonth)),
                      completeEngMonth(std::move(tempCompleteEngMonth)),
                      unicodeMyanMonth(std::move(tempUnicodeMyanMonth)),
                      zawgyiMyanMonth(std::move(tempZawgyiMyanMonth))
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


    private:
        XMwayLoon::Randomizer::NumberRandomizer objNumberRandomizer;
         myanMonthsContainer myanMonths{
                Month("Jan", "January", "ဇန်နဝါရီ", "ဇန္နဝါရီ"),
                Month("Feb", "February", "ဖေဖော်ဝါရီ", "ေဖေဖာ္ဝါရီ"),
                Month("Mar", "March", "မတ်", "မတ္"),
                Month("Apr", "April", "ဧပရယ်", "ဧပရယ္"),
                Month("May", "May", "မေ", "ေမ"),
                Month("Jun", "June", "ဇွန်", "ဇြန္"),
                Month("Jul", "July", "ဇူလိုင်", "ဇူလိုင္"),
                Month("Aug", "August", "ဩဂုတ်", "ဩဂုတ္"),
                Month("Sept", "September", "စက်တင်ဘာ", "စက္တင္ဘာ"),
                Month("Oct", "October", "အောက်တိုဘာ", "ေအာက္တိုဘာ"),
                Month("Nov", "November", "နိုဝင်ဘာ", "ႏိုဝင္ဘာ"),
                Month("Dec", "December", "ဒီဇင်ဘာ", "ဒီဇင္ဘာ")

        };
       pcg objPCG;
        DateType objDateType;

    public:

        DateRandomizer();
        DateRandomizer(DateType tmp_objDateType);
        std::string convertCompleteEngMonthToMyan(std::string engMonth,const XML_RE::Encoding &encoding);
        std::string convertShortEngMonthToMyan(std::string engMonth,const XML_RE::Encoding &encoding);
        std::string generateRandomEngDate(const std::string &format);
        std::string convertEngDateToMyan(std::string engDate, const XML_RE::Encoding &encoding);
        std::string getRandomMyanDate(const std::string &format,const XML_RE::Encoding &encoding);
        
    };






}


#endif //FAKEDATAGENERATOR_DATE_H
