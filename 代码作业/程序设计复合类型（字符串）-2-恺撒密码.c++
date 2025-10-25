#include <iostream>
#include <cctype>
#include<string>
#include<string.h>
using namespace std;
int main() {
    char a[300];
    cin.getline(a, 200, '\n');
    int n;
    cin >> n;
    size_t str = strlen(a);
    for (int i = 0; i < str; i++) {
        if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)) {
            if (a[i] >= 65 && a[i] <= 90 && n < 0 && a[i] + n < 65)a[i] = a[i] + 26 + n;
            else if (a[i] >= 65 && a[i] <= 90 && n > 0 && a[i] + n > 90)a[i] = a[i] - 26 + n;
            else if (a[i] >= 97 && a[i] <= 122 && n < 0 && a[i] + n < 97)a[i] = a[i] + n + 26;
            else if (a[i] >= 97 && a[i] <= 122 && n > 0 && a[i] + n > 122)a[i] = a[i] - 26 + n;
            else a[i] += n;
        }
    }
    for (int i = 0; i < str; i++) {
        cout << a[i];
    }
    return 0;
}