#include <iostream>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
    string a,b;
    size_t cd;
int main() {
    while (1) {
        getline(cin, a,'\n');
        if (a == " ")break;
        size_t len = a.length();
        cd += len;
        reverse(a.begin(), a.end());
        b = a + b;
    }
    reverse(b.begin(), b.end());
    cout << cd << endl << b;
    return 0;
}