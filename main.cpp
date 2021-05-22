#include "CWLib.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(NULL, ".UTF8");

    string fileName;
    cout << "Enter name of file to save & load students:" << endl;
    cin >> fileName;
    string decrFileName = fileName + ".sys";
    string tempFileName = fileName + ".tmp";
    fileName += ".CW";
    FILE *file, *decrypted_file, *temp;
    fopen_s(&file, fileName.c_str(), "rb");
    if (!file)
        fopen_s(&file, fileName.c_str(), "wb+");
    fopen_s(&temp, tempFileName.c_str(), "wb+");
    string com = "attrib -R ";
    com += fileName;
    system(com.c_str());

    HCRYPTPROV hProv;
    HCRYPTKEY hSessionKey;
    if(!CryptAcquireContext(&hProv, nullptr, nullptr, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)){
        cout << "Error, getting encryption context: " << GetLastError() << endl;
        fclose(file);
        fclose(temp);
        return 1;
    }
    cout << "Cryptographic provider successfully initialized!" << endl;

    if(!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)){
        cout << "Error, generating session key for encryption: " << GetLastError() << endl;
        fclose(file);
        fclose(temp);
        return 1;
    }
    cout << "Session key successfully generated!" << endl;

    while (!feof(file)){    //  Encrypting file because it isn't (export and import of keys don't work)
        char buff[2];
        fgets(reinterpret_cast<char *>(&buff), 2, file);
        if(feof(file))
            break;
        if (buff[0] != 0) {
            CWEncrypt(&buff[0], hSessionKey);
            fputs(buff, temp);
        } else {
            fputc(0, temp);
        }
    }
    fclose(file);
    fclose(temp);

    fopen_s(&temp, tempFileName.c_str(), "rb");
    fopen_s(&decrypted_file, decrFileName.c_str() , "wb+");
    while (!feof(temp)){
        char buff[2];
        fgets(reinterpret_cast<char *>(&buff), 2, file);
        if(feof(temp))
            break;
        if (buff[0] != 0) {
            CWDecrypt(&buff[0], hSessionKey);
            fputs(buff, decrypted_file);
        } else {
            fputc(0, decrypted_file);
        }
    }
    fclose(temp);
    fclose(decrypted_file);


    menu(fileName.c_str());

    fopen_s(&decrypted_file, decrFileName.c_str() , "rb");
    fopen_s(&temp, tempFileName.c_str(), "wb+");

    fseek(temp, 0, SEEK_SET);
    while (!feof(decrypted_file)){  //  Fake file encryption back (export and import of keys don't work)
        char buff[2];
        fgets(reinterpret_cast<char *>(&buff), 2, file);
        if(feof(decrypted_file))
            break;
        if (buff[0] != 0) {
            CWEncrypt(&buff[0], hSessionKey);
            fputs(buff, temp);
        } else {
            fputc(0, temp);
        }
    }

    fclose(decrypted_file);
    fclose(temp);
    remove(decrFileName.c_str());
    remove(tempFileName.c_str());
    com = "attrib +R ";
    com += fileName;
    system(com.c_str());
    CryptDestroyKey(hSessionKey);
    return 0;
}
