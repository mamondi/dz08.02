#include "else.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filePath;
    cout << "������ ���� �� HTML-�����: ";
    cin >> filePath;

    if (validateHTML(filePath)) {
        cout << "���� � ������� HTML-����������." << endl;
    }
    else {
        cout << "���� �� � ������� HTML-����������." << endl;
    }

    return 0;
}