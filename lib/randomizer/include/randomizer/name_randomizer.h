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


namespace XMwayLoon::Randomizer {

    namespace tag {
        struct syllable;
        struct gender;
        struct position;
        struct wordAmount;
    }





    class NameRandomizer {

    public:

        enum class Gender {
            male = 1, female = 2, both=3
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
           /* Property(std::pair<std::string,std::string> tmp_syllable,Gender tmp_gender,
                     Position tmp_position, WordAmount tmp_wordAmount)
            : syllable(tmp_syllable),
              gender(tmp_gender),
              position(tmp_position),
              wordAmount(tmp_wordAmount)
            {}*/

        };

        void getFemaleName();
        void getMaleName();
        void getRandomName();
        void getName(Gender gender,XMwayLoon::Randomizer::Encoding encoding);











    };

}


#endif //SHINMWAYLOON_NAME_H
