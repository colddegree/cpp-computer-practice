/*
 * Написать программу, которая бы выводила на экран расписание ваших дисциплин
 * для того дня недели, номер которой вводит пользователь.
 */

#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    wcout << L"Расписание Б8204, 2 подгруппа" << endl;

    int weekday_idx_number;
    wcout << L"Выберите день недели (порядковый номер): ";
    cin >> weekday_idx_number;

    cout << endl;

    switch(weekday_idx_number) {
    case 1:
        wcout << L"Понедельник:" << endl;
        wcout << "  " << L"10:10 Математический анализ ПЗ, D734" << endl;
        wcout << "  " << L"11:50 Математический анализ Л, D738" << endl;
        wcout << "  " << L"13:30 Иностранный язык ПЗ, D547/D548/D949" << endl;
        wcout << "  " << L"15:10 Геометрия и топология Л, D412/542" << endl;
        break;
    case 2:
        wcout << L"Вторник:" << endl;
        wcout << "  " << L"8:30 (нечёт) Геометрия и топология ПЗ, D945" << endl;
        wcout << "  " << L"10:10 Математическая логика ПЗ, L558" << endl;
        wcout << "  " << L"13:30 Дифференциальные уравнения математической физики Л, D738" << endl;
        wcout << "  " << L"15:10 Элективные курсы по физической культуре ПЗ, S" << endl;
        break;
    case 3:
        wcout << L"Среда:" << endl;
        wcout << "  " << L"8:30 Компьютерный практикум ЛР, D734" << endl;
        wcout << "  " << L"10:10 Компьютерный практикум ЛР, D734" << endl;
        wcout << "  " << L"11:50 Структуры и алгоритмы компьютерной обработки данных Л, D548" << endl;
        wcout << "  " << L"13:30 Структуры и алгоритмы компьютерной обработки данных ЛР, D734a" << endl;
        break;
    case 4:
        wcout << L"Четверг:" << endl;
        wcout << "  " << L"8:30 Математическая логика ПЗ, D741" << endl;
        wcout << "  " << L"10:10 Алгебра ПЗ, D741" << endl;
        wcout << "  " << L"11:50 (нечёт) Алгебра Л, D738" << endl;
        wcout << "  " << L"11:50 (чёт) Архитектура вычислительных систем и компьютерных сетей Л, D738" << endl;
        wcout << "  " << L"13:30 (чёт) Архитектура вычислительных систем и компьютерных сетей ЛР, D938" << endl;
        break;
    case 5:
        wcout << L"Пятница:" << endl;
        wcout << "  " << L"11:50 Дискретная математика Л, D654/752" << endl;
        wcout << "  " << L"13:30 Дискретная математика ПЗ, D818" << endl;
        wcout << "  " << L"15:10 Элективные курсы по физической культуре ПЗ, S" << endl;
        break;
    case 6:
        wcout << L"Суббота:" << endl;
        wcout << "  " << L"- пусто" << endl;
        break;
    case 7:
        wcout << L"Воскресенье:" << endl;
        wcout << "  " << L"- пусто" << endl;
        break;
    default:
        wcout << L"Неверный день недели" << endl;
    }

    return 0;
}
