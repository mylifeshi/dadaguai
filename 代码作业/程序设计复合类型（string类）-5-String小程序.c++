#include <iostream>
#include <string>
using namespace std;
int main() {
    string a = "";
    char n;         
    while (1) {
        cin >> n;
        if (n == 'q') {
            cout << a;
            break;
        }
        if (n == '1') cout << a.length() << endl;
        if (n == '2') if (!a.empty()) cout << a << endl;
        if (n == '3') {
            char b;
            cin >> b; 
            size_t k = a.length();
            for (size_t i = 0; i < k; i++) {
                if (b == 'L') {
                    if (a[i] >= 'A' && a[i] <= 'Z')
                        a[i] = a[i] - 'A' + 'a';
                }
                else if (b == 'U') {
                    if (a[i] >= 'a' && a[i] <= 'z')
                        a[i] = a[i] - 'a' + 'A';
                }
            }
        }
        if (n == '4') {
            string b;
            size_t p;
            cin >> b >> p;
            if (p < 0) p = 0;
            size_t m = a.length();
            if (p > m) p = m;
            string left = a.substr(0, p);
            string right = a.substr(p);
            a = left + b + right;
        }
        if (n == '5') {
            string b, c;
            cin >> b >> c;
            size_t pos = a.find(b);
            if (pos != string::npos) {
                string left = a.substr(0, pos);
                string right = a.substr(pos + b.length());
                a = left + c + right;
            }
        }
    }
    return 0;
}