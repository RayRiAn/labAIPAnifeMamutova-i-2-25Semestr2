#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int maxRecursive(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    
    int maxOfRest = maxRecursive(arr, size - 1);
    
    if (arr[size - 1] > maxOfRest) {
        return arr[size - 1];
    } else {
        return maxOfRest;
    }
}

int maxIterative(int arr[], int size) {
    int max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    srand(time(nullptr));
    
    int n;
    cout << "Сколько чисел будет в массиве? ";
    cin >> n;
    
    int arr[100];
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    int max1 = maxRecursive(arr, n);
    cout << "Максимальный элемент (рекурсия): " << max1 << endl;
    
    int max2 = maxIterative(arr, n);
    cout << "Максимальный элемент (итерация): " << max2 << endl;
    
    return 0;
}