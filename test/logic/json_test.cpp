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

TEST(JsonTest, jsonWrite) {

    json objJson;
    json innerJson;
    string path = Initializer::directory+"/key.json";

    cout <<path;
    std::ofstream file(path);

    std::vector<std::string> title= {"id","name","email","age"};
    std::vector<std::string> data= {"6","Mya","r@gmail.com","21"};



    for (int i = 0; i < 10; ++i) {

        for (int j = 0; j <4 ; ++j) {
            innerJson[title[j]] =data[j];


        }

        objJson["object"+std::to_string(i)] =innerJson;

}
    file << objJson;
}