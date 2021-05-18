#include "CWLib.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(NULL, ".UTF8");

    string fileName;
    cout << "Enter name of file to save & load students:" << endl;
    cin >> fileName;
    fileName += ".CW";
    menu(fileName.c_str());

//    string ss = "String to encode and decode!";
//    Crypto cr = *CWEncrypt(ss.c_str());
//    cout << cr.getValue()<< endl << cr.getProv() << endl << cr.getHash() << endl << cr.getSessionKey() << endl;
//
//    Crypto cr2 = *CWEncrypt(ss.c_str(), 19093368, 19161488);
//    cout << cr2.getValue()<< endl << cr2.getProv() << endl << cr2.getHash() << endl << cr2.getSessionKey() << endl;
    return 0;
}
