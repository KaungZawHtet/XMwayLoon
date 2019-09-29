#include <iostream>
#include "lib/FakeDataGeneration/include/english_date.h"
#include "lib/FakeDataGeneration/include/ph_number.h"
#include "lib/FakeDataGeneration/include/global_objects.h"
//#include "lib/FakeDataGeneration/include/inserter.h"
#include "lib/FakeDataGeneration/include/retriever.h"

#include <boost/serialization/export.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>
#include <iostream>

using namespace std;
using namespace Xlotgative;
int main() {

    std::stringstream ss;
    int numbers1[10], numbers2[10];
    for (int i = 0; i < 10; i++) {
        numbers1[i] = i;
    }

    boost::archive::text_oarchive oar(ss);
    oar << numbers1;

    boost::archive::text_iarchive iar(ss);
    iar >> numbers2;

    for (auto i : numbers2)
        std::cout << i << " ";

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