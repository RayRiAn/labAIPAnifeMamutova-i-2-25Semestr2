#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int sumDvux(int* ptr, int rows, int cols) {
    int sum = 0;
    int itog = rows * cols;
    int* end = ptr + itog;

    for (int* current = ptr; current < end; current++) {
        sum += *current;
    }

    return sum;
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned>(time(nullptr)));

    const int ROWS = rand() % 4 + 2; 
    const int COLS = rand() % 4 + 2; 

    cout << "Сгенерирован массив размером " << ROWS << "x" << COLS << endl;

    int* nums = new int[ROWS * COLS];

    for (int i = 0; i < ROWS * COLS; ++i) {
        nums[i] = rand() % 20 + 1;
    }

    cout << "\nСгенерированный массив:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << nums[i * COLS + j] << "\t";
        }
        cout << endl;
    }

    int result = sumDvux(nums, ROWS, COLS);

    cout << "\nСумма всех элементов массива: " << result << endl;

    delete[] nums;
    return 0;
}
