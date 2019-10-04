#include <iostream>
#include "lib/FakeDataGeneration/include/english_date.h"
#include "lib/FakeDataGeneration/include/ph_number.h"
#include "lib/FakeDataGeneration/include/number.h"
#include "lib/FakeDataGeneration/include/global_objects.h"
//#include "lib/ShinMwayLoon/include/inserter.h"
#include "lib/FakeDataGeneration/include/retriever.h"
#include <sstream>
#include <thread>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {

      /*
       * IMPORTANT
       * Xlotgative::ShinMwayLoon::ShinMwayLoonEnglishDate objEnglishDate;
      Xlotgative::ShinMwayLoon::ptr_string ptr= objEnglishDate.getRandomMyanDate("%d-%Switch-%Y",UNICODE);
      std::cout<<*ptr;*/


    /*Xlotgative::ShinMwayLoon::PhoneNumber objPhoneNumber;
    Xlotgative::ShinMwayLoon::ptr_string ptr=objPhoneNumber.getRandomMyanPhNum(Xlotgative::ShinMwayLoon::PhoneNumber::CountryCodeFlag::random);
    std::cout<<*ptr;*/

    /*Xlotgative::ShinMwayLoon::Number objNumber;
    Xlotgative::ShinMwayLoon::ptr_string ptr=objNumber.generateMyanNum(2000);
    std::cout<<*ptr;*/


    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";











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