#include <iostream>
#include <cctype>
#include<string>
#include<string.h>
using namespace std;
int main() {
    char str1[200],cc[200];
    cin.getline(str1, 200,'\n');
    size_t len = strlen(str1);
    for (int i = 0; i < len; i++) {
        cout << "*";
        cc[i] = '*';
    }
    cc[len] = '\0';
    cout << endl;
    while (1) {
        char str2[200];
        cin.getline(str2, 200, '\n');
        if ( strcmp(str2, "end") == 0) {
            for (int i = 0; i < len; i++)cout << cc[i];
            break;
        }
        for (int i = 0; i < len; i++) if (str1[i] == str2[i])cc[i] = str2[i];
        if (strcmp(str2, str1) == 0) {
            for (int i = 0; i < len; i++)cout << str2[i];
            break;
        }
        for (int i = 0; i < len; i++)cout << cc[i];
        cout << endl;
    }
    return 0;
}
