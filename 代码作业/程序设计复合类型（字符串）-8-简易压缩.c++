#include <iostream>
#include <cstring>
#include<string>
using namespace std;
char a[1000],b[1000];
int c[1000],d;
int main() {
    cin.getline(a, 200);
    size_t len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            b[d] = a[i];
            c[d]++;
        }
        else {
            if (a[i] == b[d]) {
                if (c[d] == 9) {
                    d++;
                    b[d] = a[i];
                    c[d] = 1;
                }
                else c[d]++;
            }
            else {
                d++;
                b[d] = a[i];
                c[d] = 1;
            }
        }
    }
    if (2*(d+1) >= len)cout << "压缩失败！";
    else {
        for (int i = 0; i <= d; i++) {
            cout << b[i]<< c[i];
        }
    }
    return 0;
}