/*
 * Найдите произведение цифр трёхзначного числа.
 */

#include <iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    int prod = 1;

    while (num != 0) {
        prod *= num % 10;
        num /= 10;
    }

    cout << prod << endl;

    return 0;
}
