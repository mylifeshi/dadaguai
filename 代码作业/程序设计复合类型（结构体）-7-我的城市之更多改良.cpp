#include <iostream>
#include <string>
using namespace std;
struct City {
    string name;      
    int population;   
    int farm;       
    int plantation;  
    int mine;                          
    int food() const {
        return farm * 4 + plantation * 3 - population * 2;
    }
    int gold() const {
        return plantation * 2 + mine * 2;
    }
    int productivity() const {
        return mine * 3;
    }
    void display() const {
        cout << name << " " << population << "人 "
             << (food() >= 0 ? "+" : "") << food() << "粮 "
             << (gold() >= 0 ? "+" : "") << gold() << "金 "
             << (productivity() >= 0 ? "+" : "") << productivity() << "锤" << endl;
    }
    void change(const string& type, int value) {
        if (type == "farm") {
            farm += value;
            if (farm < 0) farm = 0;
        } else if (type == "plantation") {
            plantation += value;
            if (plantation < 0) plantation = 0;
        } else if (type == "mine") {
            mine += value;
            if (mine < 0) mine = 0;
        } else if (type == "population") {
            population += value;
            if (population < 0) population = 0;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    City c;
    cin >> c.name >> c.population >> c.farm >> c.plantation >> c.mine;
    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "quit") break;
        string signValue;
        cin >> signValue;
        int sign = (signValue[0] == '+') ? 1 : -1;
        int num = 0;
        for (size_t i = 1; i < signValue.size(); i++)num = num * 10 + (signValue[i] - '0');
        c.change(cmd, sign * num);
        c.display();
    }
    return 0;
}