#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string words[] = { "C++", "is", "one", "of", "the", "world's", "most", "popular", "programming", "languages" };

    int size = 10;
    string** ptrArray = new string * [size];

    for (int i = 0; i < size; i++) {
        ptrArray[i] = &words[i];
    }

    cout << "Исходный порядок:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    int polovina = size / 2;

    for (int i = 0; i < polovina; i++) {
        string* itog = ptrArray[i];
        ptrArray[i] = ptrArray[i + polovina];
        ptrArray[i + polovina] = itog;
    }

    cout << "После замены половин:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *ptrArray[i] << " "; 
    }
    cout << endl;


    delete[] ptrArray;

    return 0;
}