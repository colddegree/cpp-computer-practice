/*
 * ����������� ����������, ������� �� � �������� ������� ���������� ����� �����
 * � ���������� ��������� �� ��� � ������ ����� � ���������� ������� ����� ������� � UI.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;

    int a;
    int sum = 0;
    while (true) {
        cin >> a;
        nums.push_back(a);
        sum += a;
        cout << (double) sum / nums.size() << endl;
    }

    return 0;
}
