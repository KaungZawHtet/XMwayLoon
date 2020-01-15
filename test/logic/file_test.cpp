//
// Created by Kaung Zaw Htet on 2020-01-10.
//
#include <gtest/gtest.h>
#include <filesystem>
#include <sqlite_orm/sqlite_orm.h>
#include <sqlite3.h>
#include <fstream>
namespace fs = std::filesystem;
using namespace sqlite_orm;
TEST(FileTest, directoryTest) {

    std::string home = fs::path(getenv("HOME"));

    std::string directory=home+"/"+"XMwayLoon";

    if(!fs::exists(directory)){

        std::cerr<< directory;
        fs::create_directory(directory);
    } else
    {
        directory=home+"/"+"XMwayLoon2";
        std::cerr<< directory;
        fs::create_directory(directory);

    }


}

struct User{
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::unique_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};

TEST(FileTest, dbTest) {
    std::string home = fs::path(getenv("HOME"));

    std::string directory=home+"/"+"XMwayLoon";

    if(!fs::exists(directory)){

        std::cerr<< directory<<std::endl;
        fs::create_directory(directory);
    }


    directory= directory+"/"+"db.sqlite";
    std::cerr<<directory<<std::endl;

    auto storage = make_storage("/Users/kaungzawhtet/XMwayLoon/db.sqlite3",
                                make_table("users",
                                           make_column("id", &User::id, autoincrement(), primary_key()),
                                           make_column("first_name", &User::firstName),
                                           make_column("last_name", &User::lastName),
                                           make_column("birth_date", &User::birthDate),
                                           make_column("image_url", &User::imageUrl),
                                           make_column("type_id", &User::typeId)),
                                make_table("user_types",
                                           make_column("id", &UserType::id, autoincrement(), primary_key()),
                                           make_column("name", &UserType::name, default_value("name_placeholder"))));



    User user{-1, "Jonh", "Doe", 664416000, std::make_unique<std::string>("url_to_heaven"), 3 };

    auto insertedId = storage.insert(user);
    std::cerr << "insertedId = " << insertedId << std::endl;      //  insertedId = 8
    user.id = insertedId;

    User secondUser{-1, "Alice", "Inwonder", 831168000, {} , 2};
    insertedId = storage.insert(secondUser);
    secondUser.id = insertedId;
}

TEST(FileTest, dbCreateTest) {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("/Users/kaungzawhtet/XMwayLoon/test.sqlite3", &db);
    sqlite3_close(db);
}

class directory{

public:
    static std::string home;
    static std::string getHome();
};

TEST(FileTest, staticTest) {

    std::cerr << directory::getHome();
}

std::string directory::getHome() {

    return directory::home;


}


std::string directory::home = fs::path(getenv("HOME"));

