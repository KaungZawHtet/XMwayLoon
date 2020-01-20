//
// Created by Kaung Zaw Htet on 2020-01-10.
//
#include <model/db/initializer.h>
#include <stdlib.h>
#include <dry_comparisons/dry_comparisons.h>
namespace fs = std::filesystem;
using rollbear::all_of;
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void Initializer::createDirectory() {

    if (!fs::exists(directory)) fs::create_directory(directory);
}

void Initializer::createDatabase() {

    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc) exit(rc);
    else Initializer::createTables();


}

void Initializer::createTables() {

    char *zErrMsg = 0;
    int rc1 = sqlite3_exec(db, sqlCreate_NameProperties.data(), callback, 0, &zErrMsg);
    int rc2 = sqlite3_exec(db, sqlCreate_CustomTypeName.data(), callback, 0, &zErrMsg);
    int rc3 = sqlite3_exec(db, sqlCreate_LastRan.data(), callback, 0, &zErrMsg);
    int rc4 = sqlite3_exec(db, sqlCreate_CustomTypeRecord.data(), callback, 0, &zErrMsg);

    if(all_of{rc1,rc2,rc3,rc4} !=SQLITE_OK)
    {
        exit(0);
    } else{
        int rc4 = sqlite3_exec(db, sqlInsert_NameProperties.data(), callback, 0, &zErrMsg);
    }


    sqlite3_close(db);
}

void Initializer::initialize() {

    Initializer::createDirectory();
    Initializer::createDatabase();

}



