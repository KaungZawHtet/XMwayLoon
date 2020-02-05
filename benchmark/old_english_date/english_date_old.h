//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#ifndef SHINMWAYLOON_ENGLISH_DATE_H
#define SHINMWAYLOON_ENGLISH_DATE_H
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





namespace XMwayLoon::Randomizer{

    namespace tag {
        struct shortEngMonth;
        struct completeEngMonth;
        struct unicodeMyanMonth;
        struct zawgyiMyanMonth;
    }

    class EnglishDate{

        typedef std::map<std::pair <std::string,std::string>, std::pair <std::string,std::string>> type_englishMonths;
        typedef std::map<std::string, std::string> type_myanNum;



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

        XMwayLoon::Randomizer::NumberRandomizer objRandomizer;




        const myanMonthsContainer myanMonths{
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
        std::random_device objRandomDevice;
        std::unique_ptr<type_englishMonths> englishMonths;


    public:

        EnglishDate()= default;
        ptr_string convertCompleteEngMonthToMyan(const std::string &,const XML_RE::Encoding &encoding);
        ptr_string convertShortEngMonthToMyan(const std::string &,const XML_RE::Encoding &encoding);
        ptr_string generateRandomEngDate(const std::string &format);
        ptr_string convertEngDateToMyan(const std::string &engDate, const XML_RE::Encoding &encoding);
        ptr_string getRandomMyanDate(const std::string &format,const XML_RE::Encoding &encoding);

    };


}


#endif //SHINMWAYLOON_ENGLISH_DATE_H
