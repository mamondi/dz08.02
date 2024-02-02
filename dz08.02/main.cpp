#include "else.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filePath;
    cout << "Введіть шлях до HTML-файлу: ";
    cin >> filePath;

    if (validateHTML(filePath)) {
        cout << "Файл є валідним HTML-документом." << endl;
    }
    else {
        cout << "Файл не є валідним HTML-документом." << endl;
    }

    return 0;
}