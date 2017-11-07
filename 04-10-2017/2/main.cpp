/*
 * Заполнить массив из 42-ух элементов нечётными числами от -42 до 42.
 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int get_random_number(int, int);

const int ARR_MAX_SIZE = 42;
const int ARR_MIN_VALUE = -42;
const int ARR_MAX_VALUE = 42;

int main() {

    srand( time(NULL) );

    vector<int> nums;

    for (int i = 0; i < ARR_MAX_SIZE; i++) {
        int rand_num;

        do
            rand_num = get_random_number(ARR_MIN_VALUE, ARR_MAX_VALUE);
        while ( (rand_num % 2) != 1 );

        nums.push_back(rand_num);
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;

    return 0;
}

int get_random_number(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}
