#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <Windows.h>

using namespace std;

bool validateHTML(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "������� �������� �����!" << endl;
        return false;
    }

    stack<string> tagStack;
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        size_t pos = 0;
        while ((pos = line.find('<', pos)) != string::npos) {
            size_t endPos = line.find('>', pos);
            if (endPos == string::npos) {
                cerr << "������� � ����� " << lineNumber << ": ��� �� ��������." << endl;
                return false;
            }

            string tag = line.substr(pos + 1, endPos - pos - 1);
            if (tag.empty() || tag[0] == '/') {
                cerr << "������� � ����� " << lineNumber << ": ����������� ���." << endl;
                return false;
            }

            if (tag.back() == '/') {
            }
            else if (tag[0] == '/') {
                if (tagStack.empty()) {
                    cerr << "������� � ����� " << lineNumber << ": ������ ����������� ���." << endl;
                    return false;
                }

                string openTag = tagStack.top();
                tagStack.pop();

                if (openTag != tag.substr(1)) {
                    cerr << "������� � ����� " << lineNumber << ": ������ ����." << endl;
                    return false;
                }
            }
            else {
                tagStack.push(tag);
            }

            pos = endPos + 1;
        }
    }

    if (!tagStack.empty()) {
        cerr << "�������: ���������� �������� ����." << endl;
        return false;
    }

    return true;
}