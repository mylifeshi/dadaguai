#include <iostream>
using namespace std;

/****************** TODO ******************/
long long a=1, b=1, c;
long long fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}
/**************** TODO-END ****************/

int main()
{
    int num = 0; // 斐波那契数列的项数

    cin >> num;
    cout << "斐波那契数列中第" << num
        << "项的值为" << fibonacci(num) << "。" << endl;

    return 0;
}