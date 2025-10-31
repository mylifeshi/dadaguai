#include <iostream>
#include <string>
using namespace std;
struct City {
    string name;     
    int population;  
    int farms;       
    City(string n, int p, int f) : name(n), population(p), farms(f) {}
    int food_output() const {
        return farms * 4 - population * 2;
    }
    void print_info() const {
        int food = food_output();
        cout << name << " " << population << "人 ";
        if (food >= 0)
            cout << "+" << food << "粮" << endl;
        else
            cout << food << "粮" << endl;
    }
    void operate(const string& cmd, int value, char op) {
        if (cmd == "farm") {
            if (op == '+') farms += value;
            else farms -= value;
            if (farms < 0) farms = 0;
        } 
        else if (cmd == "population") {
            if (op == '+') population += value;
            else population -= value;
            if (population < 0) population = 0;
        }
        print_info();  
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string name;
    int population, farms;
    cin >> name >> population >> farms;
    City city(name, population, farms);
    string cmd;
    while (1) {
        cin >> cmd;
        if (cmd == "quit") break;
        char op;
        int value;
        cin >> op >> value;
        city.operate(cmd, value, op);
    }
    return 0;
}
