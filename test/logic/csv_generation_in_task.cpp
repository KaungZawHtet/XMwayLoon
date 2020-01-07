//
// Created by Kaung Zaw Htet on 2020-01-06.
//
#include <fstream>
#include <gtest/gtest.h>

using namespace std;
const std::string filePath = "~/Desktop/csv_test.csv";
const std::string filePath2 = "~/Desktop/input.txt";

void writeBlankLine() {

}

void readByLineNumber() {

    cerr << "this is line : " << std::endl;
    std::ifstream infile;
    int linenumber = 6;
    int lines_read = 0;
    std::string line;
    infile.open(filePath2, ios::in);
    getline(infile, line);
   cerr << line << std::endl;
    infile.close();

}



TEST(NumberTest, readByLineNumber) {

    readByLineNumber();
}