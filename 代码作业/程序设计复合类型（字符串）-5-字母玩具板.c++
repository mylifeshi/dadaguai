#include <iostream>
#include <cctype>
#include<string>
#include<string.h>
using namespace std;  
char a[10][10];
int W(int x, int y) {
    if (x == 1)return 1;
    if (a[x - 1][y] != '*')W(x - 1, y);
    if (a[x - 1][y] == '*') {
        a[x - 1][y] = a[x][y];
        a[x][y] = '*';
        W(x - 1, y);
    }
    return 1;
}
int S(int x, int y) {
    if (x == 5)return 1;
    if (a[x + 1][y] != '*')S(x + 1, y);
    if (a[x + 1][y] == '*') {
        a[x + 1][y] = a[x][y];
        a[x][y] = '*';
        S(x + 1, y);
    }
    return 1;
}
int A(int x, int y) {
    if (y == 1)return 1;
    if (a[x][y-1] != '*')A(x, y-1);
    if (a[x][y-1] == '*') {
        a[x][y-1] = a[x][y];
        a[x][y] = '*';
        A(x, y-1);
    }
    return 1;
}
int D(int x, int y) {
    if (y == 5)return 1;
    if (a[x][y+1] != '*')D(x , y+1);
    if (a[x][y+1] == '*') {
        a[x][y+1] = a[x][y];
        a[x][y] = '*';
        D(x, y+1);
    }
    return 1;
}
int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    } 
    char b;
    cin >> b;
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                if (a[i][j] != '*') {
                    if (b == 'W')W(i, j);
                    if (b == 'A')A(i, j);
                    if (b == 'S')S(i, j);
                    if (b == 'D')D(i, j);
                }
            }
        }
    cout << "位移后的盘面状态为：" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
