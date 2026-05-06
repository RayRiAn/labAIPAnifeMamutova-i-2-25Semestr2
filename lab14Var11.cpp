#ifndef MAX_ARRAY_H
#define MAX_ARRAY_H

int naibolshiy_element(int massiv[], int razmer);

#endif

/*Файл 1: max_array.h

Как создать: Обозреватель решений → ПКМ на "Файлы заголовков" → Добавить → Новый элемент → "Файл заголовка (.h)" → Имя: max_array.h → Добавить*/

#include "max_array.h"

int naibolshiy_element(int massiv[], int razmer) {
    int max = massiv[0];
    for (int i = 1; i < razmer; i++) {
        if (massiv[i] > max) {
            max = massiv[i];
        }
    }
    return max;
}

//Файл 2: max_array.cpp

#include <iostream>
#include "max_array.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    int n1, n2;
    
    cout << "=== Поиск максимального элемента в массивах ===" << endl;
    
    cout << "Введите размер первого массива: ";
    cin >> n1;
    
    int* massiv1 = new int[n1];
    cout << "Введите " << n1 << " элементов: ";
    for (int i = 0; i < n1; i++) {
        cin >> massiv1[i];
    }
    
    cout << "Введите размер второго массива: ";
    cin >> n2;
    
    int* massiv2 = new int[n2];
    cout << "Введите " << n2 << " элементов: ";
    for (int i = 0; i < n2; i++) {
        cin >> massiv2[i];
    }
    
    int max1 = naibolshiy_element(massiv1, n1);
    int max2 = naibolshiy_element(massiv2, n2);
    
    cout << "Максимальный элемент первого массива: " << max1 << endl;
    cout << "Максимальный элемент второго массива: " << max2 << endl;
    
    delete[] massiv1;
    delete[] massiv2;
    
    return 0;
}

//Файл 3. main.cpp