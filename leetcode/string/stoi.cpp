#include "../all.h";

using namespace std;

int convertDigit(const char c) {
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

int myAtoi(string str) {
    int result = 0;
    if (str.front() == '-') {
        for (int i = 1; i < str.size(); ++i) {
            if (str.size() - 1 - i > 0) result += pow(10, str.size() - 1 - i) * convertDigit(str[i]);
            else result += convertDigit(str[i]);
        }
        result = -result;
    } else {
        for (int i = 0; i < str.size(); ++i) {
            if (str.size() - 1 - i > 0) result += pow(10, str.size() - 1 - i) * convertDigit(str[i]);
            else result += convertDigit(str[i]);
        }
    }
    return result;
}

int main() {
    string s = "123";
    cout << myAtoi(s) << endl;
    string s1 = "    010";
    cout << myAtoi(s1) << endl;
    return 0;
}
