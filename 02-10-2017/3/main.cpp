/*
 * Задать матрицу M x N (в файле / в тексте кода приложения / другим способом).
 * Написать программу, которая бы заменяла столбец I и строку J матрицы числами -1,
 * если элемент (I, J) - нулевой. Свести к минимуму расход памяти и время выполнения программы.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void print_matrix(vector< vector<int> >);

int main() {

    ifstream fi("input.txt");

    int n, m;
    fi >> n;
    fi >> m;

    vector< vector<int> > matrix;
    int a;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            fi >> a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }

    print_matrix(matrix);
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = -1;
                for (int k = 0; k < m; k++)
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                for (int k = 0; k < n; k++)
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
            }
        }
    }

    print_matrix(matrix);

    fi.close();

    return 0;
}

void print_matrix(vector< vector<int> > a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++ ) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
