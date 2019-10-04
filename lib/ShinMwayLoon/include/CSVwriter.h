//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#ifndef SHINMWAYLOON_CSVWRITE_H
#define SHINMWAYLOON_CSVWRITE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>

/*
 * A class to create and write data in a csv file.
 */


namespace Xlotgative::ShinMwayLoon{


template<typename T>
class CSVwriter
{
    std::string fileName;
    std::string delimeter;
    int linesCount;

public:

    CSVwriter(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm), linesCount(0)
    {}
    /*
     * Member function to store a range as comma seperated value
     */

    void addDatainRow(T first, T last);
};

}



#endif //SHINMWAYLOON_CSVWRITE_H
