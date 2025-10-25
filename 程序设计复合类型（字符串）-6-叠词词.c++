#include <iostream>
#include <cstring>
using namespace std;
char a[300], b[200][200];
int n, k, length, c[200], l, d[200];
int s[200], e[200];
int main() {
    for (int i = 0; i < 200; i++) c[i] = d[i] = s[i] = e[i] = 0;
    n = 1;
    k = 1;
    cin.getline(a, 200, '\n');
    int len = (int)strlen(a);
    int l = 0;
    for (int i = 0; i < len; i++) {
        char ch = a[i];
        if (ch == ' ') {
            if (k > 1) {
                b[n][k] = '\0';
                e[n] = i;
                l = n;
                n++;
                k = 1;
            }
            continue;
        }
        if (k == 1) s[n] = i;
        if (ch == 39 || ch == '-') {
            b[n][k] = ch;
            k++;
            continue;
        }
        if ((ch < 65 || (ch > 90 && ch < 97) || ch > 122)&&(ch<48||ch>57)) {
            if (k > 1) {
                b[n][k] = '\0';
                e[n] = i;
                l = n;
                n++;
                k = 1;
            }
            b[n][1] = ch;
            b[n][2] = '\0';
            s[n] = i;
            e[n] = i + 1;
            d[n] = 1;
            l = n;
            n++;
            k = 1;
            continue;
        }
        b[n][k] = ch;
        k++;
    }
    if (k > 1) {
        b[n][k] = '\0';
        e[n] = len;
        l = n;
    }
    else if (l != n) n--;
    if (n < 1) return 0;
    for (int i = 1; i < n; i++) {
        if (d[i] || d[i + 1]) continue;
        int p = 1;
        bool isSame = true;
        while (true) {
            char x = b[i][p], y = b[i + 1][p];
            if (x != y) { 
                isSame = false;
                break;
            }
            if (x == '\0' && y == '\0') break;
            if (x == '\0' || y == '\0') { 
                isSame = false; 
                break;
            }
            p++;
        }
        if (isSame) c[i] = 1;
    }
    bool r[300] = { false };
    for (int i = 1; i <= n; i++) {
        if (c[i]) {
            int sp = e[i];
            if (sp >= 0 && sp < len && a[sp] == ' ') r[sp] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (c[i]) continue;
        int p = 1;
        while (b[i][p] != '\0') {
            cout << b[i][p];
            p++;
        }
        int j = i + 1;
        while (j <= n && c[j]) j++;
        if (j > n) break;
        bool hasEffectiveSpace = false;
        int from = e[i];
        int to = s[j] - 1;
        if (from <= to) {
            for (int pos = from; pos <= to; pos++) {
                if (pos >= 0 && pos < len && a[pos] == ' ' && !r[pos]) {
                    hasEffectiveSpace = true;
                    break;
                }
            }
        }
        if (hasEffectiveSpace) cout << " ";
    }
    return 0;
}