#include <iostream>
#include "lib/ShinMwayLoon/include/english_date_old.h"
#include "lib/ShinMwayLoon/include/ph_number.h"
#include "lib/ShinMwayLoon/include/number.h"
#include "lib/ShinMwayLoon/include/global_objects.h"
//#include "lib/ShinMwayLoon/include/inserter.h"
#include "lib/ShinMwayLoon/include/retriever.h"
#include "lib/ShinMwayLoon/include/pangram.h"
#include <sstream>
#include <thread>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>




int main() {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%B-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cout<<*ptr;

      /*
       * IMPORTANT
       * Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%Switch-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cout<<*ptr;*/


    /*Xlotgative::ShinMwayLoon::PhoneNumber obj_PhoneNumber;
    Xlotgative::ShinMwayLoon::ptr_string ptr=objPhoneNumber.getRandomMyanPhNum(Xlotgative::ShinMwayLoon::PhoneNumber::CountryCodeFlag::random);
    std::cout<<*ptr;*/

    /*Xlotgative::ShinMwayLoon::Number obj_Number;
    Xlotgative::ShinMwayLoon::ptr_string ptr=objNumber.generateMyanNum(30);
    std::cout<<*ptr;*/


    /*unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";*/

    /*Xlotgative::ShinMwayLoon::Pangram obj_Pangram;
    Xlotgative::ShinMwayLoon::ptr_string ptr = obj_Pangram.getPangram(Xlotgative::ShinMwayLoon::Encoding::Random);
    std::cout<<*ptr;*/










    return  0;
}

/*
 *
 * {
    // Creating an object of CSVWriter
    CSVWriter writer("example.csv");

    std::vector<std::string> dataList_1 = { "20", "hi", "99" };

    // Adding vector to CSV File
    writer.addDatainRow(dataList_1.begin(), dataList_1.end());

    // Create a set of integers
    std::set<int> dataList_2 = { 3, 4, 5};

    // Adding Set to CSV File
    writer.addDatainRow(dataList_2.begin(), dataList_2.end());

    std::string str = "abc";

    // Adding characters in a string in csv file.
    writer.addDatainRow(str.begin(), str.end());

    // An array of int
    int arr [] = {3,4,1};

    // Wrote an elements in array to csv file.
    writer.addDatainRow(arr , arr + sizeof(arr) / sizeof(int));

    return 0;
}
 */