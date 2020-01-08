//
// Created by Kaung Zaw Htet on 2020-01-06.
//
#include <fstream>
#include <gtest/gtest.h>
#include <logic/CSV_writer.h>
using namespace std;
const std::string filePath = "~/Desktop/csv_test.csv";
const std::string filePath2 = "~/Desktop/input.txt";

void writeCSVinTask() {

/*
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");


    string line;

    int id_count[2]; //user first, ticket second


    ifstream file_in("lib/persistence.txt");
    if (file_in.is_open()) {

        int i = 0;
        while (getline(file_in, line)) {
            id_count[i] = stoi(line);
            i++;
        }
        file_in.close();
    }

    CSVWriter csv;
    csv << id_count[0] << id_count[1] << "NULL" << ticket::id << "0" << ss.str() << ss.str();
    csv.writeToFile("ticket_id.csv", true);


    ofstream file_out;
    file_out.open("lib/persistence.txt", ios::out);
    file_out << ++id_count[0] << '\n' << ++id_count[1];
    file_out.close();*/

}





TEST(NumberTest, writeCSVinTask) {


}