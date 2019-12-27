//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_NAME_H
#define SHINMWAYLOON_NAME_H


#include <string>
#include "global_objects.h"
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>


namespace Xlotgative::ShinMwayLoon {

    namespace tag {
        struct syllable;
        struct gender;
        struct position;
        struct wordAmount;
    }





    class Name {


        enum class Gender {
            male = 1, female = 2, both
        };
        enum class Position {
            onlyFront = 1, bothFrontMiddle = 2, onlyMiddle = 3, bothMiddleLast = 4, onlyLast = 5
        };
        enum class WordAmount {
            one = 1, two = 2,three=3
        };

        struct Property {
            std::pair<std::string,std::string> syllable;
            Gender gender;
            Position position;
            WordAmount wordAmount;
            Property(std::pair<std::string,std::string> tmp_syllable,Gender tmp_gender,
                     Position tmp_position, WordAmount tmp_wordAmount)
            : syllable(tmp_syllable),
              gender(tmp_gender),
              position(tmp_position),
              wordAmount(tmp_wordAmount)
            {}

        };

        typedef boost::multi_index::multi_index_container<
                Property,
                boost::multi_index::indexed_by<
                        boost::multi_index::ordered_unique<
                                boost::multi_index::tag<tag::gender>,
                                boost::multi_index::member<Property, Gender, &Property::gender>>,
                        boost::multi_index::ordered_unique<
                                boost::multi_index::tag<tag::position>,
                                boost::multi_index::member<Property, Position, &Property::position>>,
                        boost::multi_index::ordered_unique<
                                boost::multi_index::tag<tag::wordAmount>,
                                boost::multi_index::member<Property, WordAmount, &Property::wordAmount>>
                >> propertyContainer;

        const propertyContainer syllable{

            //က start
                Property(std::make_pair("ကို",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကျော်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကောင်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကြည်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ကြူ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကြိုင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကျော့",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကြွေ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ကျူး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကြွယ်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကေ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ကလျာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                /// ခ start

                Property(std::make_pair("ခန့်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ချစ်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ချူး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ချော",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ချမ်းသာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("ခိုင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ချမ်းမြေ့",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ချယ်ရီ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ချို",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ခင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ဂျူး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဂျွန်",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                /// င
                Property(std::make_pair("ငုဝါ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ငယ်ငယ်",""), Gender::female, Position::onlyMiddle, WordAmount::two),

                //စ
                Property(std::make_pair("စု",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("စော",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("စံ",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("စိုင်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("စွမ်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("စန္ဒာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("စန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("စိန်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("စည်သူ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("စိမ့်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //ဆ
                Property(std::make_pair("ဆောင်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဆွေ",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဆန်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဆု",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဆုန်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဆင့်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //ဇ
                Property(std::make_pair("ဇူး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဇွန်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဇင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဇာ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဇူလိုင်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဇေယျာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဇော်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဇွဲ",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                //ည
                Property(std::make_pair("ညီ",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဉာဏ်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ညွန့်",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                //ဍ
                Property(std::make_pair("ဍေး",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //တ
                Property(std::make_pair("တင့်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("တင်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("တိုး",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                //ထ
                Property(std::make_pair("ထွန်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထူး",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထက်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထိုက်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထွဋ်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထွေး",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထား",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ထိန်လင်း",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                //န
                Property(std::make_pair("နိုင်",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နောင်",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("နိုး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နန္ဒာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("နွေး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နု",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နှင်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နီ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("နေ",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("နွယ်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("နော်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //ပ
                Property(std::make_pair("ပန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ပွင့်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ပိုး",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ပြည့်ဖိုး",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ပြည့်စုံ",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("ပိုင်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ပုလဲ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ပြုံး",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //ဖ
                Property(std::make_pair("ဖူး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဖြူ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဖွေး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဖြိုး",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                //ဗ
                Property(std::make_pair("ဗိုလ်",""), Gender::both, Position::onlyMiddle, WordAmount::one),


                //ဘ
                Property(std::make_pair("ဘို",""), Gender::male, Position::onlyMiddle, WordAmount::one),


                //မ
                Property(std::make_pair("မေ",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မောင်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မော်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("မူမူ",""), Gender::female, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("မင်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မိ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မျိုး",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("မြင့်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မာ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("မြ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မြတ်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("မိုး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("မို့မို့",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("မိုမို",""), Gender::female, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("မေတ္တာ",""), Gender::both, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("မာယာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("မြိုင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                //ယ
                Property(std::make_pair("ယွန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ယု",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ယဥ်",""), Gender::female, Position::onlyMiddle, WordAmount::one),


                //ရ
                Property(std::make_pair("ရန်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ရဲ",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ရီ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ရွှေ",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("ရင်ရင်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ရီ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ရတနာ",""), Gender::female, Position::onlyMiddle, WordAmount::three),

                Property(std::make_pair("ရာဇာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("ရွက်ဝါ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ရွှန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),


                //လ
                Property(std::make_pair("လွန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("လှ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("လွင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("လု",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("လင်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("လွှမ်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("လဲ့",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("လှိုင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("လတ်",""), Gender::female, Position::onlyMiddle, WordAmount::one),


                //ဝ
                Property(std::make_pair("ဝါ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဝင်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဝင့်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဝဿာန်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဝသုန်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဝတ်ရီ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဝေ",""), Gender::female, Position::onlyMiddle, WordAmount::one),


                //သ
                Property(std::make_pair("သွန်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သီ",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သိန်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သန်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သောင်း",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သစ်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သာ",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သဲ",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သက်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သု",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သူဇာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သူရ",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သစ္စာ",""), Gender::both, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သီဟ",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သွင်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သီတာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("သန္တာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("သင်း",""), Gender::female, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သော်",""), Gender::both, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သန့်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သွေး",""), Gender::male, Position::onlyMiddle, WordAmount::one),

                Property(std::make_pair("သဇင်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("သီရိ",""), Gender::female, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သာဓု",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("သူရိန်",""), Gender::male, Position::onlyMiddle, WordAmount::two),

                Property(std::make_pair("သွယ်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("သက်မွန်",""), Gender::female, Position::onlyMiddle, WordAmount::two),


                //ဟ
                Property(std::make_pair("ဟန်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဟေမာန်",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဟေမာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဟိန်း",""), Gender::male, Position::onlyMiddle, WordAmount::one),


                //အ

                Property(std::make_pair("အောင်",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("အား",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("အိမ့်",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("အေး",""), Gender::female, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("အာကာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("အိ",""), Gender::female, Position::onlyMiddle, WordAmount::one),


                //ဧဪဥ...
                Property(std::make_pair("ဦး",""), Gender::male, Position::onlyMiddle, WordAmount::one),
                Property(std::make_pair("ဩဇာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဧရာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဥက္ကာ",""), Gender::male, Position::onlyMiddle, WordAmount::two),
                Property(std::make_pair("ဥမ္မာ",""), Gender::female, Position::onlyMiddle, WordAmount::two),





        };








    };

}


#endif //SHINMWAYLOON_NAME_H
