#include <iostream>
using namespace std;

void atm(int money)
{
    /****************** TODO ******************/
        static int b = 100;          // 初始余额 100 元
        if (money > 0) {                   // 存钱
            b += money;
            cout << "存钱成功" << endl;
        }
        else {                           // 取钱
            int w = -money;
            if (w > b) {      // 余额不足
                cout << "余额不足" << endl;
            }
            else {                       // 取钱成功
                b -= w;
                cout << "取钱成功" << endl;
            }
        }
        cout << "当前余额为" << b << "元。" << endl;
    /**************** TODO-END ****************/
}

int main()
{
    int query;

    cin >> query;
    while (query != 0)
    {
        atm(query);
        cin >> query;
    }

    return 0;
}