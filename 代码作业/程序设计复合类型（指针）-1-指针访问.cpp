#include <iostream>
using namespace std;

/****************** TODO ******************/
void print_variable(int *p)
{
    cout << p << " " << *p << endl;
}
/**************** TODO-END ****************/

int main()
{
    int a = 0;
  
    cin >> a;

    print_variable(&a);

    return 0;
}