//
// Created by Kaung Zaw Htet on 2020-01-10.
//

#ifndef XMWAYLOON_INITIALIZER_H
#define XMWAYLOON_INITIALIZER_H


#include <string>
#include <filesystem>
#include <sqlite3.h>

#include <string>
#include <sqlite_orm/sqlite_orm.h>
#include <model/db/orm.h>

class Initializer {

private:
    static void createTable();

    static void loadNamePropertiesData();

public:
    static inline std::string home = std::filesystem::path(getenv("HOME"));
    static inline std::string directory = home + "/" + ".XMwayLoon";
    static inline std::string dbPath = directory + "/cache.sqlite3";
    static inline sqlite3 *db;

    static constexpr std::string_view sqlCreate_NameProperties = R"(CREATE TABLE IF NOT EXISTS name_properties (
  id integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  unicode_syllable varchar(20),
  zawgyi_syllable varchar(20),
  gender integer(2),
  position integer(2),
  syllable_amount integer(2)
);

CREATE UNIQUE INDEX IF NOT EXISTS IndexNPid ON name_properties (id ASC);)";

    static constexpr std::string_view sqlCreate_CustomTypeRecord = R"(CREATE TABLE IF NOT EXISTS custom_type_record (
  id integer PRIMARY KEY NOT NULL,
  custom_type_name_id integer,
  unicode_unit varchar(255),
  zawgyi_unit varchar(255),
  FOREIGN KEY (custom_type_name_id) REFERENCES custom_type_name (id)
);)";

    static constexpr std::string_view sqlCreate_CustomTypeName = R"(CREATE TABLE IF NOT EXISTS custom_type_name (
  id integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  type_name char(255)
);)";


    static constexpr std::string_view sqlCreate_LastRan = R"(CREATE TABLE IF NOT EXISTS last_randomization (
    id integer PRIMARY KEY NOT NULL,
    type_name varchar(128)
    );
    )";

//TODO:: need fix
    static constexpr std::string_view sqlInsert_NameProperties = R"(INSERT INTO "name_properties" VALUES (1,'ကို','ကို',1,1,1);
INSERT INTO "name_properties" VALUES (2,'ကျော်','ေက်ာ္',1,1,1);
INSERT INTO "name_properties" VALUES (3,'ကောင်း','ေကာင္း',1,1,1);
INSERT INTO "name_properties" VALUES (4,'ကြည်','ၾကည္',3,3,1);
INSERT INTO "name_properties" VALUES (5,'ကြူ','ၾကဴ',2,2,1);
INSERT INTO "name_properties" VALUES (6,'ကြိုင်','ႀကိဳင္',2,2,1);
INSERT INTO "name_properties" VALUES (7,'ကျော့','ေက်ာ့',2,2,1);
INSERT INTO "name_properties" VALUES (8,'ကြွေ','ေႂကြ',2,2,1);
INSERT INTO "name_properties" VALUES (9,'ကျူး','က်ဴး',2,2,1);
INSERT INTO "name_properties" VALUES (10,'ကြွယ်','ႂကြယ္',2,2,1);
INSERT INTO "name_properties" VALUES (11,'ကေ','ေက',2,2,1);
INSERT INTO "name_properties" VALUES (12,'ကလျာ','ကလ်ာ',2,2,2);
INSERT INTO "name_properties" VALUES (13,'ခန့်','ခန္႔',1,1,1);
INSERT INTO "name_properties" VALUES (14,'ချစ်','ခ်စ္',3,3,1);
INSERT INTO "name_properties" VALUES (15,'ချူး','ခ်ဴး',2,2,1);
INSERT INTO "name_properties" VALUES (16,'ချော','ေခ်ာ',2,2,1);
INSERT INTO "name_properties" VALUES (17,'ချမ်းသာ','ခ်မ္းသာ',1,1,1);
INSERT INTO "name_properties" VALUES (18,'ခိုင်','ခိုင္',2,2,1);
INSERT INTO "name_properties" VALUES (19,'ချမ်းမြေ့','ခ်မ္းေျမ့',2,2,2);
INSERT INTO "name_properties" VALUES (20,'ချယ်ရီ','ခ်ယ္ရီ',2,2,2);
INSERT INTO "name_properties" VALUES (21,'ချို','ခ်ိဳ',2,2,1);
INSERT INTO "name_properties" VALUES (22,'ခင်','ခင္',2,2,1);
INSERT INTO "name_properties" VALUES (23,'ဂျူး','ဂ်ဴး',2,2,1);
INSERT INTO "name_properties" VALUES (24,'ဂျွန်','ဂြၽန္',1,1,1);
INSERT INTO "name_properties" VALUES (25,'ငုဝါ','ငုဝါ',2,2,2);
INSERT INTO "name_properties" VALUES (26,'ငယ်ငယ်','ငယ္ငယ္',2,2,2);
INSERT INTO "name_properties" VALUES (27,'စု','စု',2,2,1);
INSERT INTO "name_properties" VALUES (28,'စော','ေစာ',1,1,1);
INSERT INTO "name_properties" VALUES (29,'စံ','စံ',1,1,1);
INSERT INTO "name_properties" VALUES (30,'စိုင်း','စိုင္း',1,1,1);
INSERT INTO "name_properties" VALUES (31,'စွမ်း','စြမ္း',1,1,1);
INSERT INTO "name_properties" VALUES (32,'စန္ဒာ','စႏၵာ',2,2,2);
INSERT INTO "name_properties" VALUES (33,'စန်း','စန္း',2,2,1);
INSERT INTO "name_properties" VALUES (34,'စိန်','စိန္',2,2,1);
INSERT INTO "name_properties" VALUES (35,'စည်သူ','စည္သူ',1,1,1);
INSERT INTO "name_properties" VALUES (36,'စိမ့်','စိမ့္',2,2,1);
INSERT INTO "name_properties" VALUES (37,'ဆောင်း','ေဆာင္း',2,2,1);
INSERT INTO "name_properties" VALUES (38,'ဆွေ','ေဆြ',3,3,1);
INSERT INTO "name_properties" VALUES (39,'ဆန်း','ဆန္း',3,3,1);
INSERT INTO "name_properties" VALUES (40,'ဆု','ဆု',2,2,1);
INSERT INTO "name_properties" VALUES (41,'ဆုန်','ဆုန္',2,2,1);
INSERT INTO "name_properties" VALUES (42,'ဆင့်','ဆင့္',2,2,1);
INSERT INTO "name_properties" VALUES (43,'ဇူး','ဇူး',2,2,1);
INSERT INTO "name_properties" VALUES (44,'ဇွန်','ဇြန္',2,2,1);
INSERT INTO "name_properties" VALUES (45,'ဇင်','ဇင္',2,2,1);
INSERT INTO "name_properties" VALUES (46,'ဇာ','ဇာ',2,2,1);
INSERT INTO "name_properties" VALUES (47,'ဇူလိုင်','ဇူလိုင္',2,2,2);
INSERT INTO "name_properties" VALUES (48,'ဇေယျာ','ေဇယ်ာ',1,1,2);
INSERT INTO "name_properties" VALUES (49,'ဇော်','ေဇာ္',1,1,1);
INSERT INTO "name_properties" VALUES (50,'ဇွဲ','ဇြဲ',1,1,1);
INSERT INTO "name_properties" VALUES (51,'ညီ','ညီ',1,1,1);
INSERT INTO "name_properties" VALUES (52,'ဉာဏ်','ဉာဏ္',1,1,1);
INSERT INTO "name_properties" VALUES (53,'ညွန့်','ၫြန္႔',1,1,1);
INSERT INTO "name_properties" VALUES (54,'ဍေး','ေဍး',2,2,1);
INSERT INTO "name_properties" VALUES (55,'တင့်','တင့္',3,3,1);
INSERT INTO "name_properties" VALUES (56,'တင်','တင္',3,3,1);
INSERT INTO "name_properties" VALUES (57,'တိုး','တိုး',1,1,1);
INSERT INTO "name_properties" VALUES (58,'ထွန်း','ထြန္း',3,3,1);
INSERT INTO "name_properties" VALUES (59,'ထူး','ထူး',1,1,1);
INSERT INTO "name_properties" VALUES (60,'ထက်','ထက္',3,3,1);
INSERT INTO "name_properties" VALUES (61,'ထွဋ်','ထြဋ္',1,1,1);
INSERT INTO "name_properties" VALUES (62,'ထွေး','ေထြး',3,3,1);
INSERT INTO "name_properties" VALUES (63,'ထား','ထား',2,2,1);
INSERT INTO "name_properties" VALUES (64,'ထိန်လင်း','ထိန္လင္း',1,1,2);
INSERT INTO "name_properties" VALUES (65,'နိုင်','ႏိုင္',3,3,1);
INSERT INTO "name_properties" VALUES (66,'နောင်','ေနာင္',1,1,1);
INSERT INTO "name_properties" VALUES (67,'နိုး','ႏိုး',2,2,1);
INSERT INTO "name_properties" VALUES (68,'နန္ဒာ','နႏၵာ',2,2,2);
INSERT INTO "name_properties" VALUES (69,'နွေး','ေႏြး',2,2,1);
INSERT INTO "name_properties" VALUES (70,'နု','ႏု',2,2,1);
INSERT INTO "name_properties" VALUES (71,'နှင်း','ႏွင္း',2,2,1);
INSERT INTO "name_properties" VALUES (72,'နီ','နီ',2,2,1);
INSERT INTO "name_properties" VALUES (73,'နေ','ေန',1,1,1);
INSERT INTO "name_properties" VALUES (74,'နွယ်','ႏြယ္',2,2,1);
INSERT INTO "name_properties" VALUES (75,'နန်း','နန္း',2,2,1);
INSERT INTO "name_properties" VALUES (76,'နော်','ေနာ္',2,2,1);
INSERT INTO "name_properties" VALUES (77,'ပန်း','ပန္း',2,2,1);
INSERT INTO "name_properties" VALUES (78,'ပွင့်','ပြင့္',2,2,1);
INSERT INTO "name_properties" VALUES (79,'ပိုး','ပိုး',2,2,1);
INSERT INTO "name_properties" VALUES (80,'ပြည့်ဖိုး','ျပည့္ဖိုး',1,1,2);
INSERT INTO "name_properties" VALUES (81,'ပြည့်စုံ','ျပည့္စုံ',1,1,2);
INSERT INTO "name_properties" VALUES (82,'ပိုင်','ပိုင္',3,3,1);
INSERT INTO "name_properties" VALUES (83,'ပုလဲ','ပုလဲ',2,2,2);
INSERT INTO "name_properties" VALUES (84,'ပြုံး','ၿပဳံး',2,2,1);
INSERT INTO "name_properties" VALUES (85,'ဖူး','ဖူး',2,2,1);
INSERT INTO "name_properties" VALUES (86,'ဖြူ','ျဖဴ',2,2,1);
INSERT INTO "name_properties" VALUES (87,'ဖွေး','ေဖြး',2,2,1);
INSERT INTO "name_properties" VALUES (88,'ဖြိုး','ၿဖိဳး',3,3,1);
INSERT INTO "name_properties" VALUES (89,'ဗိုလ်','ဗိုလ္',3,3,1);
INSERT INTO "name_properties" VALUES (90,'ဘို','ဘို',1,1,1);
INSERT INTO "name_properties" VALUES (91,'မေ','ေမ',2,2,1);
INSERT INTO "name_properties" VALUES (92,'မောင်','ေမာင္',3,3,1);
INSERT INTO "name_properties" VALUES (93,'မော်','ေမာ္',2,2,1);
INSERT INTO "name_properties" VALUES (94,'မူမူ','မူမူ',2,2,2);
INSERT INTO "name_properties" VALUES (95,'မင်း','မင္း',1,1,1);
INSERT INTO "name_properties" VALUES (96,'မိ','မိ',2,2,1);
INSERT INTO "name_properties" VALUES (97,'မျိုး','မ်ိဳး',3,3,1);
INSERT INTO "name_properties" VALUES (98,'မြင့်','ျမင့္',3,3,1);
INSERT INTO "name_properties" VALUES (99,'မာ','မာ',2,2,1);
INSERT INTO "name_properties" VALUES (100,'မြ','ျမ',2,2,1);
INSERT INTO "name_properties" VALUES (101,'မြတ်','ျမတ္',3,3,1);
INSERT INTO "name_properties" VALUES (102,'မိုး','မိုး',2,2,1);
INSERT INTO "name_properties" VALUES (103,'မို့မို့','မို႔မို႔',2,2,2);
INSERT INTO "name_properties" VALUES (104,'မိုမို','မိုမို',2,2,2);
INSERT INTO "name_properties" VALUES (105,'မေတ္တာ','ေမတၱာ',3,3,2);
INSERT INTO "name_properties" VALUES (106,'မာယာ','မာယာ',2,2,2);
INSERT INTO "name_properties" VALUES (107,'ယွန်း','ယြန္း',2,2,1);
INSERT INTO "name_properties" VALUES (108,'ယု','ယု',2,2,1);
INSERT INTO "name_properties" VALUES (109,'ယဥ်','ယဥ္',2,2,1);
INSERT INTO "name_properties" VALUES (110,'ရန်','ရန္',1,1,1);
INSERT INTO "name_properties" VALUES (111,'ရဲ','ရဲ',1,1,1);
INSERT INTO "name_properties" VALUES (112,'ရီ','ရီ',2,2,1);
INSERT INTO "name_properties" VALUES (113,'ရွှေ','ေ႐ႊ',3,3,1);
INSERT INTO "name_properties" VALUES (114,'ရင်ရင်','ရင္ရင္',2,2,2);
INSERT INTO "name_properties" VALUES (115,'ရီ','ရီ',2,2,1);
INSERT INTO "name_properties" VALUES (116,'ရတနာ','ရတနာ',2,2,3);
INSERT INTO "name_properties" VALUES (117,'ရာဇာ','ရာဇာ',1,1,2);
INSERT INTO "name_properties" VALUES (118,'ရွက်ဝါ','႐ြက္ဝါ',2,2,2);
INSERT INTO "name_properties" VALUES (119,'ရွှန်း','႐ႊန္း',2,2,1);
INSERT INTO "name_properties" VALUES (120,'လွန်း','လြန္း',2,2,1);
INSERT INTO "name_properties" VALUES (121,'လှ','လွ',2,2,1);
INSERT INTO "name_properties" VALUES (122,'လွင်','လြင္',2,2,1);
INSERT INTO "name_properties" VALUES (123,'လု','လု',2,2,1);
INSERT INTO "name_properties" VALUES (124,'လင်း','လင္း',3,3,1);
INSERT INTO "name_properties" VALUES (125,'လွှမ်း','လႊမ္း',1,1,1);
INSERT INTO "name_properties" VALUES (126,'လဲ့','လဲ့',2,2,1);
INSERT INTO "name_properties" VALUES (127,'လှိုင်','လႈိင္',2,2,1);
INSERT INTO "name_properties" VALUES (128,'လတ်','လတ္',2,2,1);
INSERT INTO "name_properties" VALUES (129,'ဝါ','ဝါ',2,2,1);
INSERT INTO "name_properties" VALUES (130,'ဝင်း','ဝင္း',2,2,1);
INSERT INTO "name_properties" VALUES (131,'ဝင့်','ဝင့္',2,2,1);
INSERT INTO "name_properties" VALUES (132,'ဝဿာန်','ဝႆာန္',2,2,2);
INSERT INTO "name_properties" VALUES (133,'ဝသုန်','ဝသုန္',2,2,2);
INSERT INTO "name_properties" VALUES (134,'ဝတ်ရီ','ဝတ္ရီ',2,2,2);
INSERT INTO "name_properties" VALUES (135,'ဝေ','ေဝ',2,2,1);
INSERT INTO "name_properties" VALUES (136,'သွန်း','သြန္း',2,2,1);
INSERT INTO "name_properties" VALUES (137,'သီ','သီ',2,2,1);
INSERT INTO "name_properties" VALUES (138,'သိန်း','သိန္း',3,3,1);
INSERT INTO "name_properties" VALUES (139,'သန်း','သန္း',3,3,1);
INSERT INTO "name_properties" VALUES (140,'သောင်း','ေသာင္း',3,3,1);
INSERT INTO "name_properties" VALUES (141,'သစ်','သစ္',1,1,1);
INSERT INTO "name_properties" VALUES (142,'သာ','သာ',1,1,1);
INSERT INTO "name_properties" VALUES (143,'သဲ','သဲ',2,2,1);
INSERT INTO "name_properties" VALUES (144,'သက်','သက္',2,2,1);
INSERT INTO "name_properties" VALUES (145,'သု','သု',2,2,1);
INSERT INTO "name_properties" VALUES (146,'သူဇာ','သူဇာ',2,2,2);
INSERT INTO "name_properties" VALUES (147,'သူရ','သူရ',1,1,2);
INSERT INTO "name_properties" VALUES (148,'သစ္စာ','သစၥာ',3,3,2);
INSERT INTO "name_properties" VALUES (149,'သီဟ','သီဟ',1,1,2);
INSERT INTO "name_properties" VALUES (150,'သွင်','သြင္',2,2,1);
INSERT INTO "name_properties" VALUES (151,'သီတာ','သီတာ',2,2,2);
INSERT INTO "name_properties" VALUES (152,'သန္တာ','သႏၲာ',2,2,2);
INSERT INTO "name_properties" VALUES (153,'သင်း','သင္း',2,2,1);
INSERT INTO "name_properties" VALUES (154,'သော်','ေသာ္',3,3,1);
INSERT INTO "name_properties" VALUES (155,'သန့်','သန္႔',1,1,1);
INSERT INTO "name_properties" VALUES (156,'သွေး','ေသြး',1,1,1);
INSERT INTO "name_properties" VALUES (157,'သဇင်','သဇင္',2,2,2);
INSERT INTO "name_properties" VALUES (158,'သီရိ','သီရိ',2,2,2);
INSERT INTO "name_properties" VALUES (159,'သာဓု','သာဓု',1,1,2);
INSERT INTO "name_properties" VALUES (160,'သူရိန်','သူရိန္',1,1,2);
INSERT INTO "name_properties" VALUES (161,'သွယ်','သြယ္',2,2,1);
INSERT INTO "name_properties" VALUES (162,'သက်မွန်','သက္မြန္',2,2,2);
INSERT INTO "name_properties" VALUES (163,'ဟန်','ဟန္',2,2,1);
INSERT INTO "name_properties" VALUES (164,'ဟေမာန်','ေဟမာန္',2,2,2);
INSERT INTO "name_properties" VALUES (165,'ဟေမာ','ေဟမာ',2,2,2);
INSERT INTO "name_properties" VALUES (166,'ဟိန်း','ဟိန္း',1,1,1);
INSERT INTO "name_properties" VALUES (167,'အောင်','ေအာင္',1,1,1);
INSERT INTO "name_properties" VALUES (168,'အား','အား',1,1,1);
INSERT INTO "name_properties" VALUES (169,'အိမ့်','အိမ့္',2,2,1);
INSERT INTO "name_properties" VALUES (170,'အေး','ေအး',2,2,1);
INSERT INTO "name_properties" VALUES (171,'အာကာ','အာကာ',1,1,2);
INSERT INTO "name_properties" VALUES (172,'အိ','အိ',2,2,1);
INSERT INTO "name_properties" VALUES (173,'ဦး','ဦး',3,3,1);
INSERT INTO "name_properties" VALUES (174,'ဩဇာ','ဩဇာ',1,1,2);
INSERT INTO "name_properties" VALUES (175,'ဧရာ','ဧရာ',1,1,2);
INSERT INTO "name_properties" VALUES (176,'ဥက္ကာ','ဥကၠာ',1,1,2);
INSERT INTO "name_properties" VALUES (177,'ဥမ္မာ','ဥမၼာ',2,2,2);
INSERT INTO "name_properties" VALUES (178,'ထိုက်','ထိုက္',3,3,1);
INSERT INTO "name_properties" VALUES (179,'မြိုင်','ၿမိဳင္',2,2,1);

INSERT INTO "name_properties" VALUES (180,'ရတီ','ရတီ',2,2,2);
INSERT INTO "name_properties" VALUES (181,'သက်ထား','သက္ထား',2,2,2);
INSERT INTO "name_properties" VALUES (182,'ယမင်း','ယမင္း',2,2,2);
INSERT INTO "name_properties" VALUES (183,'၀တီ','၀တီ',2,2,2);
INSERT INTO "name_properties" VALUES (184,'သိမ့်','သိမ့္',2,1,1);
INSERT INTO "name_properties" VALUES (185,'ကောင်းကင်','ေကာင္းကင္',1,2,2);
INSERT INTO "name_properties" VALUES (186,'လမင်း','လမင္း',2,2,2);
INSERT INTO "name_properties" VALUES (187,'သုတ','သုတ',1,2,2);
)";

    static inline auto storage = sqlite_orm::make_storage
            (Initializer::dbPath,
             sqlite_orm::make_table("custom_type_record",
                                    sqlite_orm::make_column("id",
                                            &CustomTypeRecord::id,
                                            sqlite_orm::autoincrement(),
                                            sqlite_orm::primary_key()),
                                    sqlite_orm::make_column("custom_type_name_id",&CustomTypeRecord::custom_type_name_id),
                                    sqlite_orm::make_column("unicode_unit",&CustomTypeRecord::unicode_unit),
                                    sqlite_orm::make_column("zawgyi_unit",&CustomTypeRecord::zawgyi_unit)),
             sqlite_orm::make_table("custom_type_name",
                                    sqlite_orm::make_column("id",
                                                            &CustomTypeName::id,
                                                            sqlite_orm::autoincrement(),
                                                            sqlite_orm::primary_key()),
                                    sqlite_orm::make_column("type_name",&CustomTypeName::type_name))
            );

    static void initialize();

    static void createDirectory();

    static void createDatabase();
    static void createTables();

};

#endif //XMWAYLOON_INITIALIZER_H
