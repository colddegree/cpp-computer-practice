/*
 * Найдите все четырёхзначные числа, произведение цифр каждого из которых равна 42.
 */

#include <iostream>

using namespace std;

int main() {

    for (int i = 1000; i <= 9999; i++) {
        int num = i;
        int prod = 1;

        while (num != 0) {
            prod *= num % 10;
            num /= 10;
        }

        if (prod == 42) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}
