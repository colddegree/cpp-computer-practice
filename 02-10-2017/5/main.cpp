/*
 * Программе необходимо считывать квадратную бинарную матрицу (из текста кода / из файла) так,
 * чтобы значения матрицы можно было легко заменить (Ctrl + C -> Ctrl + V).
 * Тип данных значений матрицы выбирайте по своему усмотрению.
 * Реализовать алгоритм нахождения наибольшей квадратной субматрицы, значения которой одинаковые.
 * Программа должна отображать в UI исходную матрицу с индексами строк и столбцов,
 * индексы границ найденной суматрицы и саму субматрицу с индексами строк и столбцов.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int sum_of_submatrix(vector< vector<int> >, int, int, int);

int main() {

    setlocale(LC_ALL, "Russian");

    ifstream fi("input.txt");

    int n;
    fi >> n;

    vector< vector<int> > matrix;
    int a;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            fi >> a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }


    wcout << L"Исходная матрица:" << endl;
    cout << "\\ ";
    for (int j = 0; j < n; j++)
        cout << j << ' ';
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i << ' ';
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }


	int maxFrameSize = 1;
	int max_i = 0, max_j = 0;

	int frameSize = 2;
	for (int i = 0; i < n - frameSize + 1; i++) {
		for (int j = 0; j < n - frameSize + 1; j++) {

            while ( ( frameSize <= (n - max(i, j)) ) &&
                ( (sum_of_submatrix(matrix, i, j, frameSize) == 0) ||
                  (sum_of_submatrix(matrix, i, j, frameSize) == trunc( pow(static_cast<float>(frameSize), 2.0) ) ) ) ) {

                maxFrameSize = frameSize;
                max_i = i;
                max_j = j;

                frameSize++;
            }
		}
	}


	cout << endl;
	wcout << L"Индексы границ найденной субматрицы (строка, столбец):" << endl;
	wcout << L"начало " << max_i << ' ' << max_j << endl;
	wcout << L"конец  " << max_i + maxFrameSize - 1 << ' ' << max_j + maxFrameSize - 1 << endl;


    cout << endl;
    wcout << L"Найденная субматрица:" << endl;
    cout << "\\ ";
    for (int j = max_j; j < max_j + maxFrameSize; j++)
        cout << j << ' ';
    cout << endl;

    for (int i = max_i; i < max_i + maxFrameSize; i++) {
        cout << i << ' ';
        for (int j = max_j; j < max_j + maxFrameSize; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }


	fi.close();

    return 0;
}

int sum_of_submatrix(vector< vector<int> > a, int i_, int j_, int frameSize) {

	int sum = 0;

	for (int i = i_; i < frameSize + i_; i++)
		for (int j = j_; j < frameSize + j_; j++)
			sum += a[i][j];

	return sum;
}
