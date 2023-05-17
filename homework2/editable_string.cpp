//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>

using namespace std;

class String {
public:
    String() {
        s = "1234567890";
        len = 10;
    }

    explicit String(char *chars) {
        s = chars;
        len = strlen(chars);
    }

    explicit String(const string& str) {
        s = str;
        len = str.length();
    }
    int getLen() {
        return len;
    }
protected:
    string s;
    int len;
};

class EditableString : public String {
public:
    EditableString():String(){
    }
    string insert(int pos, const char c) {
        if (pos > 0 && pos <= len + 1) {
            s.insert(pos - 1, 1, c);
            len++;
        }
        return s;
    }

    string delete_c(int pos) {
        if (pos > 0 && pos <= len) {
            s.erase(s.begin() + pos - 1);
            len--;
        }
        return s;
    };

    string replace(int pos, char c) {
        if (pos > 0 && pos <= len) {
            s[pos - 1] = c;
        }
        return s;
    }
};

int main() {
    char op;
    int pos;
    char ch;
    EditableString e_str;
    string last_res;
    while (true) {
        cin >> op;
        if (op == 'i') {
            cin >> pos >> ch;
            cout << e_str.insert(pos, ch)<<endl;
        } else if (op == 'd') {
            cin >> pos;
            cout << e_str.delete_c(pos)<<endl;
        } else if (op == 'r') {
            cin >>pos>>ch;
            cout<<e_str.replace(pos,ch)<<endl;
        } else {
            break;
        }
    }
    return 0;
}
