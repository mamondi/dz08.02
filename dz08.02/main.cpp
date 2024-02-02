#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string path;
    cout << "Введіть шлях до файлу: ";
    cin >> path;

    ifstream fin(path);
    ofstream fout(path);

    if (!fin.is_open()) {
        fout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
            << "Maecenas scelerisque mauris ac mauris ultricies, "
            << "nec ultricies urna luctus. Aliquam tristique quam "
            << "sed nibh semper, sed ultricies mauris luctus. "
            << "Quisque semper scelerisque eros, "
            << "quis ultricies lectus porttitor.";
        fin.open(path);
    }

    while (true) {
        cout << "\nВиберіть дію:\n"
            << "1. Пошук рядка\n"
            << "2. Заміна рядка\n"
            << "3. Виведення файлу\n"
            << "4. Перевертання файлу\n"
            << "5. Вихід\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string find_str;
            cout << "Введіть рядок для пошуку: ";
            cin >> find_str;

            int count = 0;
            while (true) {
                string line;
                getline(fin, line);

                if (line.empty()) {
                    break;
                }

                if (line.find(find_str) != string::npos) {
                    count++;
                }
            }

            cout << "Рядок \"" << find_str << "\" зустрічається в файлі " << count << " разів." << endl;
            break;
        }

        case 2: {
            string find_str, replace_str;
            cout << "Введіть рядок для заміни: ";
            cin >> find_str;
            cout << "Введіть новий рядок: ";
            cin >> replace_str;

            int count = 0;
            while (true) {
                string line;
                getline(fin, line);

                if (line.empty()) {
                    break;
                }

                if (line.find(find_str) != string::npos) {
                    line.replace(line.find(find_str), find_str.length(), replace_str);
                    count++;
                }

                fout << line << endl;
            }

            cout << "Рядок \"" << find_str << "\" замінений на рядок \"" << replace_str << "\" " << count << " разів." << endl;
            break;
        }

        case 3: {
            while (true) {
                string line;
                getline(fin, line);

                if (line.empty()) {
                    break;
                }

                cout << line << endl;
            }
            break;
        }

        case 4: {
            while (true) {
                string line;
                getline(fin, line);

                if (line.empty()) {
                    break;
                }

                for (int i = line.length() - 1; i >= 0; i--) {
                    fout << line[i];
                }
                fout << endl;
            }
            break;
        }

        case 5: {
            return 0;
        }

        default: {
            cout << "---> Невірний вибір <---" << endl; }
          
int find_str(ifstream& fin, string find_str) {
    int count = 0;
    while (true) {
        string line;
        getline(fin, line);

        if (line.empty()) {
            break;
        }

        if (line.find(find_str) != string::npos) {
            count++;
        }
    }

    return count;
}

// Функція заміни рядка
void replace_str(ifstream& fin, ofstream& fout, string find_str, string replace_str) {
    int count = 0;
    while (true) {
        string line;
        getline(fin, line);

        if (line.empty()) {
            break;
        }

        if (line.find(find_str) != string::npos) {
            line.replace(line.find(find_str), find_str.length(), replace_str);
            count++;
        }

        fout << line << endl;
    }

    cout << "Рядок \"" << find_str << "\" замінений на рядок \"" << replace_str << "\" " << count << " разів." << endl;
}

void reverse_str(ifstream& fin, ofstream& fout) {
    while (true) {
        string line;
        getline(fin, line);

        if (line.empty()) {
            break;
        }

        for (int i = line.length() - 1; i >= 0; i--) {
            fout << line[i];
        }
        fout << endl;
    }
}
		}
	}
