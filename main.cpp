#include <iostream>
#include "lib/FakeDataGeneration/include/english_date.h"
#include "lib/FakeDataGeneration/include/ph_number.h"
#include "lib/FakeDataGeneration/include/global_objects.h"
//#include "lib/FakeDataGeneration/include/inserter.h"
#include "lib/FakeDataGeneration/include/retriever.h"
#include <sstream>

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main() {
    Xlotgative::EnglishDate objEnglishDate;

    Xlotgative::ptr_string ptr= objEnglishDate.getRandomMyanDate("%d-%b-%Y",UNICODE);

    cout<<*ptr;


    /*Xlotgative::EnglishDate objEnglishDate;
    std::string format="%d-%b-%Y";
    Xlotgative::ptr_string date=objEnglishDate.generateRandomEngDate(format) ;
    std::stringstream stream  ;
    stream << (*date);
    std::string dateString = stream.str();


    cout<<dateString<<endl;

    cout<< (*objEnglishDate.convertEngDateToMyan(dateString,UNICODE));*/


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