#include <iostream>
#include <ctime>
#include <climits>  
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int m, n;
    cout << "Введите M и N: ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Ошибка: размеры матрицы должны быть положительными" << endl;
        return 1;
    }

    int** a = new int* [m];
    cout << "\nИсходная матрица:" << endl;

    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int result = INT_MAX;
    bool found = false;

    for (int i = 0; i < m; i++) {

        bool ascending = true;
        bool descending = true;

        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] >= a[i][j + 1]) ascending = false;
            if (a[i][j] <= a[i][j + 1]) descending = false;
        }

        if (ascending || descending) {

            int minInRow = a[i][0];
            for (int j = 1; j < n; j++) {
                if (a[i][j] < minInRow) {
                    minInRow = a[i][j];
                }
            }

            if (!found) {
                result = minInRow;
                found = true;
            }
            else if (minInRow < result) {
                result = minInRow;
            }
        }
    }

    cout << "\nРезультат: ";
    if (found) {
        cout << result << " (минимальный элемент среди монотонных строк)";
    }
    else {
        cout << 0 << " (нет монотонных строк)";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}