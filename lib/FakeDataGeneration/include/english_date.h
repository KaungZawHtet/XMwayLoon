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
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;



namespace Xlotgative{

    class EnglishDate{



    public:
        std::map<std::string, pair <string,string>> myanmarDateKeywords;
        EnglishDate();
        std::map<std::string, pair <string,string>> getData();
        void convertEnglishNumberToMyanmar(std::string &,string&);
        void convertEnglishMonthToMyanmar(std::string &,string &);
        boost::gregorian::date generateRandomDate(std::string &);

        friend class boost::serialization::access;
      //  friend std::ostream & operator<<(std::ostream &os, const EnglishDate &englishDate);
        // friend std::ostream & operator<<(std::ostream &os, const bus_schedule::trip_info &ti);
        //  std::list<std::pair<trip_info, bus_route *> > schedule;
        template<class Archive>
        void serialize(Archive &archieve, const unsigned int version);
        void saveMyanmarKeywords( const char * filename);
        void restoreMyanmarKeywords( const char * filename);

        friend std::ostream & operator<< (std::ostream & outputStream, const std::map<std::string, pair <string,string>> &myanmarDateKeywords)
        {


            for (auto loopIterator=myanmarDateKeywords.begin(),endIterator = myanmarDateKeywords.end();
                 loopIterator!=endIterator;loopIterator++)
            {

                outputStream << loopIterator->first << loopIterator->second.first << loopIterator->second.second;

            }
            return outputStream;


        }





    };






}





BOOST_CLASS_VERSION(Xlotgative::EnglishDate,2);





#endif //FAKEDATAGENERATOR_ENGLISH_DATE_H
