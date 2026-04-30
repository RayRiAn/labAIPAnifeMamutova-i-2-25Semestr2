#include <iostream>
#include <string>
using namespace std;

int main() {
    string stroka;
    string samoe_dlinnoe = "";
    string tekushee = "";
    
    cout << "Введите строку: ";
    getline(cin, stroka);
    
    stroka = stroka + " ";
    
    for(int i = 0; i < stroka.length(); i++) {
        if(stroka[i] != ' ') {
            tekushee = tekushee + stroka[i];
        }
        else {
            if(tekushee.length() > samoe_dlinnoe.length()) {
                samoe_dlinnoe = tekushee;
            }
            tekushee = "";
        }
    }
    
    if(samoe_dlinnoe != "") {
        cout << "Самое длинное слово: " << samoe_dlinnoe << endl;
    }
    else {
        cout << "Строка не содержит слов" << endl;
    }
    
    return 0;
}