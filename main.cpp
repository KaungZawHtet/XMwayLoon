#include <iostream>
#include "lib/FakeDataGeneration/include/english_date.h"


using namespace std;
using namespace Xlotgative;
int main() {

    EnglishDate objED;
    string month="January";



    //objED.convertEnglishMonthToMyanmar(month);

   cout<<objED.generateRandomDate(month);
    return 0;
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