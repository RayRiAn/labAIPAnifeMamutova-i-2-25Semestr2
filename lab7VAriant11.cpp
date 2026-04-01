#include <iostream>
#include <ctime>
using namespace std;

bool isAscending(int* row, int n) {
    for (int j = 0; j < n - 1; j++) {
        if (row[j] > row[j + 1]) {
            return false;
        }
    }
    return true;
}

bool isDescending(int* row, int n) {
    for (int j = 0; j < n - 1; j++) {
        if (row[j] < row[j + 1]) {
            return false;
        }
    }
    return true;
}

int findMinInRow(int* row, int n) {
    int min = row[0];
    for (int j = 1; j < n; j++) {
        if (row[j] < min) {
            min = row[j];
        }
    }
    return min;
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    int m, n;
    cout << "Введите количество строк M: ";
    cin >> m;
    cout << "Введите количество столбцов N: ";
    cin >> n;

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

    int resultMin = 0;
    bool foundOrderedRow = false;

    for (int i = 0; i < m; i++) {

        if (isAscending(a[i], n) || isDescending(a[i], n)) {
            int minInRow = findMinInRow(a[i], n);

            cout << "\nСтрока " << i + 1 << " упорядочена, её минимальный элемент: " << minInRow;

            if (!foundOrderedRow) {
                resultMin = minInRow;
                foundOrderedRow = true;
            }

            else if (minInRow < resultMin) {
                resultMin = minInRow;
            }
        }
    }

    cout << "\n\nРезультат: ";
    if (foundOrderedRow) {
        cout << "Минимальный элемент среди упорядоченных строк = " << resultMin << endl;
    }
    else {
        cout << "0 (упорядоченные строки отсутствуют)" << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}