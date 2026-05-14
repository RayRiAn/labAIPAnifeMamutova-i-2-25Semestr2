#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int findMaxRecursive(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    
    int maxOfRest = findMaxRecursive(arr, n - 1);
    
    if (arr[n - 1] > maxOfRest) {
        return arr[n - 1];
    } else {
        return maxOfRest;
    }
}

int findMaxIterative(int arr[], int n) {
    int maxVal = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal; }

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(nullptr));
    
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    
    int* arr = new int[n];
    
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
   
    clock_t startRec = clock();
    int maxRec = findMaxRecursive(arr, n);
    clock_t endRec = clock();
    double timeRec = static_cast<double>(endRec - startRec) / CLOCKS_PER_SEC;
    
    cout << "Максимальный элемент(рекурсия): " << maxRec << endl;
    cout << "Время выполнения: " << timeRec << " секунд" << endl << endl;
    
    clock_t startIter = clock();
    int maxIter = findMaxIterative(arr, n);
    clock_t endIter = clock();
    double timeIter = static_cast<double>(endIter - startIter) / CLOCKS_PER_SEC;
   
    cout << "Максимальный элемент (итерация): " << maxIter << endl;
    cout << "Время выполнения: " << timeIter << " секунд" << endl;
    
    delete[] arr;
    return 0;
}