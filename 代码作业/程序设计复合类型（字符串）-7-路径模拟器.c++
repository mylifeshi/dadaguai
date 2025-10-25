#include <iostream>
#include <cstring>
#include<string>
using namespace std;
char a[200], b[200] = "C:\\Users\\Student";
char c[1000];
int main() {
    size_t len = strlen(b);
    for (int i = 0; i < len; i++)cout << b[i];
    cout << endl;
    while (1) {
        size_t cd = strlen(b);
        for (int i = 1; i <= 199; i++)a[i] = 0;
        cin.getline(a, 200, '\n');
        if (strcmp(a, "quit") == 0)break;
        int t = 3, s = 0, l = 0,k=0;
        while (1) {
            if (!(a[0] == 'c' && a[1] == 'd' && a[2] == ' '))break;
            if (strcmp(a, "cd .") == 0) break;
 //           cout << t <<" " << a[t] << " " << s << " " << l << " " << k << endl;
            if (a[t] == '.') s++;
            if (k==0&&s > 0 && (a[t] == 92 || a[t] == '\0')) {
                if (s == 2) {
                    size_t len2 = strlen(b);
                    int n = 0;
                    s = 0;
                    while (1) {
                        if (len2 == 0)break;
                        if (b[len2] == 92 && n != 0) {
                            b[len2] = '\0';
                            cd = len2;
                            break;
                        }
                        len2--;
                        n++;
                    }
                }
                for (int i = 1; i < 200; i++)c[i] = 0;
                l = 0;
                b[cd] = '\0';
                s = 0;
                t++;
                if (a[t] == '\0')break;
                continue;
            }
            if (a[t] == '\0') {
                b[cd] = '\\';
                cd++;
                for (int i = 0; i < l; i++) {
                    b[cd] = c[i];
                    c[i] = 0;
                    cd++;
                }
                l = 0;
                k = 0;
                t++;
                b[cd] = '\0';
                break;
            }
            if ( a[t] == 92) {
                b[cd] = '\\';
                cd++;
                for (int i = 0; i < l; i++) {
                    b[cd] = c[i];
                    c[i] = 0;
                    cd++;
                }
                s = 0;
                l = 0;
                k = 0;
                t++;
                b[cd] = '\0';
                continue;
            }
            if (a[t] != '.')k++;
            c[l] = a[t];
            l++;
            t++;
            /*if (l == 0) {
                b[cd] = '\\';
                cd++;
            }
            b[cd] = a[t];
            cd++;
            l++;
            t++;*/
        }
        size_t len = strlen(b);
        if (strcmp(b, "C:") == 0)cout << "C:\\";
        else for (int i = 0; i < len; i++)cout << b[i];
        cout << endl;
    }
    return 0;
}