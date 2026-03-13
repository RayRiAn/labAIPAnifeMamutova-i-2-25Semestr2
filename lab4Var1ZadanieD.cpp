#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    char symbol;
    char* ptr = &symbol;

    cout << "Введите любой символ: ";
    cin >> symbol;

    cout << "\nВведенный символ: " << symbol << endl;
    cout << "Символ через указатель: " << *ptr << endl;
    cout << "Адрес символа: " << (void*)ptr << endl; 

    (*ptr)++; 

    cout << "\nСледующий символ в алфавите: " << symbol << endl;
    cout << "Новый символ через указатель: " << *ptr << endl;

    return 0;
}