#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string path;
    cout << "������ ���� �� �����: ";
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
        cout << "\n������� ��:\n"
            << "1. ����� �����\n"
            << "2. ����� �����\n"
            << "3. ��������� �����\n"
            << "4. ������������ �����\n"
            << "5. �����\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string find_str;
            cout << "������ ����� ��� ������: ";
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

            cout << "����� \"" << find_str << "\" ����������� � ���� " << count << " ����." << endl;
            break;
        }

        case 2: {
            string find_str, replace_str;
            cout << "������ ����� ��� �����: ";
            cin >> find_str;
            cout << "������ ����� �����: ";
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

            cout << "����� \"" << find_str << "\" �������� �� ����� \"" << replace_str << "\" " << count << " ����." << endl;
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
            cout << "---> ������� ���� <---" << endl; }
          
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

// ������� ����� �����
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

    cout << "����� \"" << find_str << "\" �������� �� ����� \"" << replace_str << "\" " << count << " ����." << endl;
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
