#include <iostream>
using namespace std;
int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) cin >> arr[i];
    signed char* p = (signed char*)arr;
    for (int i = 0; i < 5 * sizeof(int); i++) {
        cout << (int)p[i];
        if (i != 5 * sizeof(int) - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
