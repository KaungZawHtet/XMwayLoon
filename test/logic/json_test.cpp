//
// Created by Kaung Zaw Htet on 2020-01-06.
//

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <model/db/initializer.h>
#include <fstream>
using json = nlohmann::json;
using namespace std;

TEST(JsonTest, jsonRead) {



    string path = Initializer::directory+"/exp.json";
    // read a JSON file
    std::ifstream objStream(path);
  //  std::cerr<<path <<"\n";
    json objJson;
    objStream >> objJson;

    for (auto &element : objJson)
    {
        cerr<<element["name"].get<std::string>() <<endl;

        for (auto i : element["items"])
        {
            cerr<<i.get<std::string>() <<endl;
        }

    }


    //std::cerr<< objJson.size() << endl;



}
