/*
 * Заполнить двумерный массив случайными числами от -2 до 42.
 * Посчитать сумму элементов отдельно в каждой строке и определить
 * номер строки, в которой эта сумма максимальна.
 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int get_random_number(int, int);

const int N = 5;
const int M = 8;

const int MATRIX_MIN_VALUE = -2;
const int MATRIX_MAX_VALUE = 42;

int main() {

    setlocale(LC_ALL, "Russian");

    srand( time(NULL) );

    vector< vector<int> > matrix;

    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < M; j++)
            row.push_back( get_random_number(MATRIX_MIN_VALUE, MATRIX_MAX_VALUE) );
        matrix.push_back(row);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    int max_row_sum = MATRIX_MIN_VALUE * M - 1;
    int idx_of_row_with_max_sum = -1;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += matrix[i][j];
        }
        if (sum > max_row_sum) {
            max_row_sum = sum;
            idx_of_row_with_max_sum = i;
        }
    }

    wcout << L"Номер строки с максимальной суммой: " << idx_of_row_with_max_sum << endl;

    return 0;
}


int get_random_number(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}
