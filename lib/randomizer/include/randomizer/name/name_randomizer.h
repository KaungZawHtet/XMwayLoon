//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_NAME_H
#define SHINMWAYLOON_NAME_H

#include "randomizer/faster_random.h"
#include "randomizer/root_randomizer.h"
#include <string>
#include <model/type/enums.h>
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



    class RootNameRandomizer : public RootRandomizer {


    public:


        /*enum class Position {
            onlyFront = 1, bothFrontMiddle = 2, onlyMiddle = 3, bothMiddleLast = 4, onlyLast = 5
        };
        enum class SyllableAmount {
            one = 1, two = 2, three = 3
        };*/


        struct Properties {
            int id;
            std::string unicode_syllable;
            std::string zawgyi_syllable;
            int gender;
            int position;
            int syllable_amount;
        };

    public:


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
                                        sqlite_orm::make_column("syllable_amount",&Properties::syllable_amount))
        );

        std::vector<std::string> femaleSyllablesTwo;
        std::vector<std::string> femaleSyllablesOne;
        std::vector<std::string> maleSyllablesTwo;
        std::vector<std::string> maleSyllablesOne;


        int sizeFemaleTwo;
        int sizeFemaleOne;
        int sizeMaleOne;
        int sizeMaleTwo;



        std::uniform_int_distribution<> oneDistribution;
        std::uniform_int_distribution<> twoDistribution;
        std::uniform_int_distribution<> nameTypeDistribution;
        std::uniform_int_distribution<> genderDistribution;


    public:
      //  RootNameRandomizer();
        explicit RootNameRandomizer(NameType tmp_nameType);

        std::string getTwoOne(std::vector<std::string> &vecOne,std::vector<std::string> &vecTwo,int sizeOne,int sizeTwo);
        std::string getTwo(std::vector<std::string> &vecTwo,int sizeTwo);
        std::string getTwoTwo(std::vector<std::string> &vecTwo,int sizeTwo);
        std::string getOneOne(std::vector<std::string> &vecOne,int sizeOne);
        std::string getOneOneOne(std::vector<std::string> &vecOne,int sizeOne);
        std::string getOneTwo(std::vector<std::string> &vecOne,std::vector<std::string> &vecTwo,int sizeOne,int sizeTwo);
        std::string getTwoOneOne(std::vector<std::string> &vecOne,std::vector<std::string> &vecTwo,int sizeOne,int sizeTwo);
        std::string getOneTwoOne(std::vector<std::string> &vecOne,std::vector<std::string> &vecTwo,int sizeOne,int sizeTwo);
        std::string getOneOneTwo(std::vector<std::string> &vecOne,std::vector<std::string> &vecTwo,int sizeOne,int sizeTwo);



        virtual void loadFemale()=0;
        virtual void loadMale()=0;
        std::string getFemaleName();
        std::string getMaleName();
        std::string getRandomName();
        std::string getRandom() override;
        void load() override ;



    };

    class ZgNameRandomizer: public RootNameRandomizer{

    public:
        void loadFemale() override ;
        void loadMale() override;
        explicit ZgNameRandomizer(NameType tmp_nameType);
        void load() override;

    };

    class UniNameRandomizer: public RootNameRandomizer{
    public:
        void loadFemale() override ;
        void loadMale() override;
        explicit UniNameRandomizer(NameType tmp_nameType);
        void load() override;
    };



    class NameRandomizer:public RootRandomizer{
    public:
        ZgNameRandomizer *objZgNameRandomizer;
        UniNameRandomizer *objUniNameRandomizer;
        XML_RE::Encoding encoding;
        std::uniform_int_distribution<> encodingDistribution;
        explicit NameRandomizer(NameType tmp_nameType);
        std::string getRandom() override ;
        void load() override;

    };


}





#endif //SHINMWAYLOON_NAME_H
