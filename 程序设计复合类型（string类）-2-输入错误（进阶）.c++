#include <iostream>
using namespace std;
int main() {
    int a;  
    while (true) {  
        cin >> a;  
        if (cin.fail()) {  
            cout << "输入错误" << endl;
            cin.clear();              
            cin.ignore(1000, '\n');   
        }
        else {        
            cout << a << endl;
            break;    
        }
    }
    return 0;
}