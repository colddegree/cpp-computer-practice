/*
 * Нарисовать равнобедренный треугольник из символов *. Высоту выбирает пользователь.
 */

#include <iostream>

using namespace std;

void print_isosceles_triangle(int);

int main() {

    int height;
    cin >> height;

    print_isosceles_triangle(height);

    return 0;
}

void print_isosceles_triangle(int height) {

    const char SYMBOL = '*';
    const char WHITESPACE = ' ';

    if (height < 1) return;
    if (height == 1) {
        cout << SYMBOL;
        return;
    }

    cout << string(height - 1, WHITESPACE) + SYMBOL +
        string(height - 1, WHITESPACE) << endl;

    for (int i = height - 2, j = 1; i > 0; i--, j += 2)
        cout << string(i, WHITESPACE) + SYMBOL + string(j, WHITESPACE) +
            SYMBOL + string(i, WHITESPACE) << endl;

    cout << string(height * 2 - 1, SYMBOL) << endl;
}
