/*
 * Пользователь вводит с клавиатуры числа. Затем он вводит некоторое проверочное
 * числовое значение. Программа должна найти в массиве все пары чисел таких, что
 * их сумма будет равна проверочному значению. Реализовать аналогичную программу
 * для нахождения всех троек (вместо пар) массива.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    vector<int> nums;
    string s;

    while (true) {
        cin >> s;

        if (s == ".") break;
        try {
            nums.push_back(stoi(s));
        } catch (exception &e) {
            cerr << s;
            wcerr << L" не является целым числом" << endl;
        }
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;

    int check_num;
    wcout << L"Введите проверочное число: ";
    cin >> check_num;

    vector< vector<int> > triples;

    for (int i = 1; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if ( (nums[0] + nums[i] + nums[j]) == check_num ) {
                vector<int> triple;

                triple.push_back(nums[0]);
                triple.push_back(nums[i]);
                triple.push_back(nums[j]);

                triples.push_back(triple);
            }
        }
    }

    wcout << L"Всего троек: " << triples.size() << endl;

    for (int i = 0; i < triples.size(); i++) {
        for (int j = 0; j < triples[i].size(); j++)
            cout << triples[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
