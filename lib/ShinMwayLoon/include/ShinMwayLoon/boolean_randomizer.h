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
#include <ShinMwayLoon/global_objects.h>


namespace Xlotgative::ShinMwayLoon {


    //၀ မှား မွား
    //၁ မှန် မွန္


    class BooleanRandomizer
    {
    private:

        pcg objPCG;


        std::string num[2]= {"၀","၁"};

        typedef std::pair<std::string,std::string> SPair;


        SPair alpha[2]
        = {std::make_pair( "မှား" , "မွား" ),std::make_pair( "မှန်" , "မွန္" ) };


    public:
        BooleanRandomizer();
        enum class type{num=1,alpha=2};

       std::string getAlphaBool
       (const XMwayLoon::Encoding &encoding);
       std::string getNumBool ();
       std::string getBooleanRandomizer (const BooleanRandomizer::type &type,
                               const Encoding &encoding);


    };

}


#endif //XMWAYLOON_BooleanRandomizer_H
