#include <iostream>
#include <cctype>
#include<string>
#include<string.h>
using namespace std;
int main() {
    char str1[200], str2[200];
    cin.getline(str1, 200); 
    cin.getline(str2, 200);  
    bool remove[256] = { false };  
    for (int i = 0; str2[i] != '\0'; i++) {
        remove[(unsigned char)str2[i]] = true;
    }
    char result[200];
    int k = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (!remove[(unsigned char)str1[i]]) {
            result[k++] = str1[i];
        }
    }
    result[k] = '\0'; 
    if (k == 0)
        cout << "空串" << endl;
    else
        cout << result << endl;

    return 0;
}
