#include <iostream>
#define ARRAY_LENGTH 50
using namespace std;

void decode(char* p)
{
    /****************** TODO ******************/
    char* left = p;               
    char* right = p;             
    while (*right) right++;      
    right--;                     
    while (left <= right) {
        cout << *left;         
        left++;
        if (left <= right) {     
            cout << *right;      
            right--;
        }
    }
    cout << endl;
    /**************** TODO-END ****************/
}

int main()
{
    char str[ARRAY_LENGTH] = {};
    cin.getline(str, ARRAY_LENGTH);

    decode(str);

    return 0;
}