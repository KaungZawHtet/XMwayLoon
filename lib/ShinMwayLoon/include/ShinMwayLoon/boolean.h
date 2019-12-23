//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_boolean_H
#define XMWAYLOON_boolean_H
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


    class Boolean
    {
    private:
        std::random_device objRandomDevice;

        std::string num[2]= {"၀","၁"};

        typedef std::pair<std::string,std::string> SPair;


        SPair alpha[2]
        = {std::make_pair( "မှား" , "မွား" ),std::make_pair( "မှန်" , "မွန္" ) };


    public:
        enum class type{num,alpha};
       std::string getAlphaBool
       (const Xlotgative::ShinMwayLoon::Encoding &encoding);
       std::string getNumBool ();
       std::string getBoolean (const Boolean::type &type,
                               const Encoding &encoding);


    };

}


#endif //XMWAYLOON_boolean_H
