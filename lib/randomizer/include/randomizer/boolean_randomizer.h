//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_BooleanRandomizer_H
#define XMWAYLOON_BooleanRandomizer_H
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <string>
#include <tuple>
#include <model/type/numeric_type.h>
#include <model/type/alphanumeric_type.h>
#include <randomizer/root_randomizer.h>
#include <model/type/enums.h>
#include "faster_random.h"

class T;
namespace XMwayLoon::Randomizer {


    //၀ မှား မွား
    //၁ မှန် မွန္


    class BooleanRandomizer : public RootRandomizer
    {
    private:

        pcg objPCG;


        static inline constexpr std::string_view num[2]= {"၀","၁"};

        typedef std::pair<std::string_view,std::string_view> SPair;


        static inline SPair alpha[2]
        = {std::make_pair( "မှား" , "မွား" ),std::make_pair( "မှန်" , "မွန္" ) };

        BooleanType objBoolType;


    public:
        BooleanRandomizer();
        std::string getRandom() override;
        explicit BooleanRandomizer(BooleanType tmp_objBoolType);


       std::string getAlphaBool
       (const XML_RE::Encoding &encoding);
       std::string getNumBool ();
       std::string getBoolRandom (const XML_RE::BoolType &type,
                               const XML_RE::Encoding encoding);


    };

}


#endif //XMWAYLOON_BooleanRandomizer_H
