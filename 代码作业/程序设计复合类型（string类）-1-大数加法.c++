#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    size_t la = a.length();
    size_t lb = b.length();
    if (lb > la) {
        string t = a; a = b; b = t;
        size_t tt = la; la = lb; lb = tt;
    }
    long long ia = (long long)la - 1;
    long long jb = (long long)lb - 1;
    int carry = 0;
    string res = ""; 
    while (ia >= 0 || jb >= 0 || carry != 0) {
        int da = 0, db = 0;
        if (ia >= 0) da = a[(size_t)ia] - '0'; 
        if (jb >= 0) db = b[(size_t)jb] - '0';
        int sum = da + db + carry;
        int digit = sum % 10;
        carry = sum / 10;
        res.push_back(char('0' + digit));
        ia--; jb--;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}