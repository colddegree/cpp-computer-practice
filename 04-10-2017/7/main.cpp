/*
 * Пользователь вводит дату в формате YYYYMMDD.
 * Программа должна отобразить название месяца и дня недели.
 */

#include <iostream>

using namespace std;

int get_weekday_idx_number(int, int, int);

int main() {

    setlocale(LC_ALL, "Russian");

    int y, m, d;
    cin >> y >> m >> d;

    switch(m) {
    case 1:
        wcout << L"Январь" << endl;
        break;
    case 2:
        wcout << L"Февраль" << endl;
        break;
    case 3:
        wcout << L"Март" << endl;
        break;
    case 4:
        wcout << L"Апрель" << endl;
        break;
    case 5:
        wcout << L"Май" << endl;
        break;
    case 6:
        wcout << L"Июнь" << endl;
        break;
    case 7:
        wcout << L"Июль" << endl;
        break;
    case 8:
        wcout << L"Август" << endl;
        break;
    case 9:
        wcout << L"Сентябрь" << endl;
        break;
    case 10:
        wcout << L"Октябрь" << endl;
        break;
    case 11:
        wcout << L"Ноябрь" << endl;
        break;
    case 12:
        wcout << L"Декабрь" << endl;
        break;
    default:
        wcout << L"Неверный месяц" << endl;
    }

    switch( get_weekday_idx_number(y, m, d) ) {
    case 0:
        wcout << L"Суббота" << endl;
        break;
    case 1:
        wcout << L"Воскресенье" << endl;
        break;
    case 2:
        wcout << L"Понедельник" << endl;
        break;
    case 3:
        wcout << L"Вторник" << endl;
        break;
    case 4:
        wcout << L"Среда" << endl;
        break;
    case 5:
        wcout << L"Четверг" << endl;
        break;
    case 6:
        wcout << L"Пятница" << endl;
        break;
    }

    return 0;
}

int get_weekday_idx_number(int y, int m, int d) {
    /*
     * К сожалению, эта формула не совсем верно работает для високосного года.
     * До 29 февраля включительно к формуле придётся прибавить ещё единицу,
     * чтобы получить верный день.
     */

    int m_code;

    switch(m) {
    case 1:
    case 10:
        m_code = 1;
        break;
    case 5:
        m_code = 2;
        break;
    case 8:
        m_code = 3;
        break;
    case 2:
    case 3:
    case 11:
        m_code = 4;
        break;
    case 6:
        m_code = 5;
        break;
    case 9:
    case 12:
        m_code = 6;
        break;
    case 4:
    case 7:
        m_code = 0;
        break;
    }

    int y_code = (6 + (y % 100) + (y % 100) / 4) % 7;

    return (d + m_code + y_code) % 7;
}
