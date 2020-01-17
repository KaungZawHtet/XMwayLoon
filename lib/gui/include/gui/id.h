#ifndef ID_H
#define ID_H

/*
 *wxFrame 100000 as MainFrame
 * wxMenubar 20000
 *  FirstMenu 1000
 *   MenuItem    1
 * wxNotebook 10000 as Main Notebook
 *  GeneratePage 1000
 *   Type Addition   : 100
 *      Add Combo    : 10
 *      Add Button   : 20
 *      Add List     : 30
 *   Output Amount   : 200
 *      Radio Record Number :10
 *      Spinctrl(RN)        :20
 *      Radio File Size     :30
 *      Spinctrl(FS)        :40
 *   Output Format   : 300
 *      Checkbox            :10
 *   Encode Type     : 400
 *      Radio Encoding      :10
 *   Generate Target : 500
 *   Generate Button : 600
 *
 *
 *
 *  ExtendPage 2000
 *      txtCtrl Path : 100
 *      btnBrowse    : 200
 *      btnExtend    : 300
 *
 *
 *
 *
 * */

#define MENU_ITEM_CREDIT_ID 21001
#define MENU_ITEM_ABOUT_ID 21002
//#define MENU_ITEM_PREFERENCE_ID 21002

#define BTN_ADD_TYPE_ID 1120
#define BTN_REMOVE_TYPE_ID 1121
#define CB_ADD_TYPE_ID 1110
#define LC_ADD_TYPE_ID 1130


#define RD_RECORD_NUMBER_ID 1210
#define RD_FILE_SIZE_ID 1230

#define CB_CSV_ID 1311
#define CB_JSON_ID 1312
#define CB_XML_ID 1313
#define CB_HTML_ID 1314

#define RD_UNICODE_ID 1411
#define RD_ZAWGYI_ID 1412
#define RD_UNIFORM_RANDOM_ID 1413
#define RD_CUSTOM_ID 1414


#define BTN_TARGET_ID 1500
#define TC_TARGET_ID 1501


#define BTN_GENERATE_ID 1600

///////////////

#define BTN_BROWSE_BY_FILE_ID 2100
#define BTN_EXTEND_BY_FILE_ID 2200
#define TC_PATH_BY_FILE_ID 2300




#endif // ID_H
