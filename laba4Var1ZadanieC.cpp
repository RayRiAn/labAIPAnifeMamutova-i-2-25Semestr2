#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int number;
    cout << "Введите число: ";
    cin >> number;

    int* ptr = &number;

    cout << "\nЗначение числа (через указатель): " << *ptr << endl;
    cout << "Адрес числа в памяти: " << ptr << endl;

    (*ptr)++;

    cout << "\nПосле увеличения на 1:" << endl;
    cout << "Новое значение числа: " << number << endl;
    cout << "Значение через указатель: " << *ptr << endl;

    return 0;
}