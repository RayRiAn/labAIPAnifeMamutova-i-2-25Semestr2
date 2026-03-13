#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[100];
    int* ptr = arr;

    for (int i = 0; i < n; i++) {
        *(ptr + i) = rand() % 100;
    }

    // А - вывод массива через указатель
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    int DO = *(ptr + n - 1);
    cout << "Последний элемент: " << DO << endl;

    int razn = 0;
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) != DO) {
            razn++;
        }
    }
    cout << "Количество элементов, отличных от последнего: " << razn << endl;

    // Б 
    int a;
    cout << "Введите число a: ";
    cin >> a;

    if (a == 0) {
        cout << "На ноль делить нельзя!" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(ptr + i) % a == 0) {
            count++;
        }
    }
    cout << "Количество элементов, кратных " << a << ": " << count << endl;

    // В - поиск двузначных чисел
    cout << "Двузначные числа в массиве: ";
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (*(ptr + i) >= 10 && *(ptr + i) <= 99) {
            cout << *(ptr + i) << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "В массиве нет двузначных чисел";
    }
    cout << endl;

    return 0;
}