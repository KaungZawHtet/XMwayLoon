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
#include <model/db/initializer.h>
#include <sqlite_orm/sqlite_orm.h>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
namespace XMwayLoon::Randomizer {


    class NameRandomizer {


    public:


        enum class Position {
            onlyFront = 1, bothFrontMiddle = 2, onlyMiddle = 3, bothMiddleLast = 4, onlyLast = 5
        };
        enum class SyllableAmount {
            one = 1, two = 2, three = 3
        };

        struct Properties {
            int id;
            std::string unicode_syllable;
            std::string zawgyi_syllable;
            XML_RE::Gender gender;
            int position;
            int syllable_amount;
        };

    private:
        pcg objPCG;

        NameType objNameType;


        static inline auto storage = sqlite_orm::make_storage
                (Initializer::dbPath,
                        sqlite_orm::make_table("name_properties",
                                sqlite_orm::make_column("id",
                                        &Properties::id,
                                        sqlite_orm::autoincrement(),
                                        sqlite_orm::primary_key()),
                                        sqlite_orm::make_column("unicode_syllable",&Properties::unicode_syllable),
                                        sqlite_orm::make_column("zawgyi_syllable",&Properties::zawgyi_syllable),
                                        sqlite_orm::make_column("gender",&Properties::gender),
                                        sqlite_orm::make_column("position",&Properties::position),
                                        sqlite_orm::make_column("syllableAmount",&Properties::syllable_amount))
        );


    public:
        NameRandomizer();
        explicit NameRandomizer(NameType tmp_nameType);


        std::string getFemaleName();

        std::string getMaleName();

        std::string getRandomName();

        std::string getName();


    };

}


#endif //SHINMWAYLOON_NAME_H
