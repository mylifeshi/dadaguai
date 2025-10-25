#include <iostream>
#include <cctype>
using namespace std;
int main() {
    char input[200]; 
    cin.getline(input, 200); 
    int count = 0;  
    for (int i = 0; input[i] != '\0'; i++) {
        if (islower(input[i])) {  
            input[i] = toupper(input[i]);  
            count++; 
        }
    } 
    cout <<"共转换" << count <<"个字母"<< endl;
    cout << input << endl;
    return 0;
}