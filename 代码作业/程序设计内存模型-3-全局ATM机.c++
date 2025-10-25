#include <iostream>
using namespace std;

int balance = 100;

/****************** TODO ******************/
void print_balance() {
    cout << "当前余额为" << balance << "元。" << endl;
}

void save_money(int m) {
    balance += m;
    cout << "存钱成功" << endl;
    print_balance();
}

void retrieve_money(int m) {
    if (m > balance) {
        cout << "余额不足" << endl;
    }
    else {
        balance -= m;
        cout << "取钱成功" << endl;
    }
    print_balance();
}
/**************** TODO-END ****************/

void atm_manager(int money)
{
    if (money > 0) {
        save_money(money);
    }
    else if (money < 0) {
        retrieve_money(-money);
    }
    print_balance();
}

int main()
{
    int query;

    cin >> query;
    while (query != 0)
    {
        atm_manager(query);
        cin >> query;
    }

    return 0;
}