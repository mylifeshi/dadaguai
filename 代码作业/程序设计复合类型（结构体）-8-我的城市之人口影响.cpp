#include <iostream>
#include <string>
using namespace std;
struct City {
    string name;      
    int population;   
    int farm;         
    int plantation;   
    int mine;         
    bool hasFactory;  
    bool hasMarket;   
    City(string n, int p, int f)
        : name(n), population(p), farm(f),
          plantation(0), mine(0),
          hasFactory(false), hasMarket(false) {}
    int food() const {
        return farm * 4 + plantation * 3 - population * 2;
    }
    int gold() const {
        int result = 0;
        result += plantation * 2 + mine * 2;
        if (hasMarket) result += population * 2;
        if (hasFactory) result -= 10;
        return result;
    }
    int hammer() const {
        int result = 0;
        result += mine * 3;
        result += population;
        if (hasFactory) result += population * 2;
        return result;
    }
    void print() const {
        cout << name << " " << population << "人 "
             << (food() >= 0 ? "+" : "") << food() << "粮 "
             << (gold() >= 0 ? "+" : "") << gold() << "金 "
             << (hammer() >= 0 ? "+" : "") << hammer() << "锤" << endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string name;
    int population, farm;
    cin >> name >> population >> farm;
    City city(name, population, farm);
    string cmd;
    while (cin >> cmd) {
        if (cmd == "quit") break;
        if (cmd == "farm" || cmd == "plantation" || cmd == "mine" || cmd == "population") {
            char sign;
            int num;
            cin >> sign >> num;
            if (num < 0) num = 0;
            if (cmd == "farm") {
                if (sign == '+') city.farm += num;
                else city.farm = max(0, city.farm - num);
            } else if (cmd == "plantation") {
                if (sign == '+') city.plantation += num;
                else city.plantation = max(0, city.plantation - num);
            } else if (cmd == "mine") {
                if (sign == '+') city.mine += num;
                else city.mine = max(0, city.mine - num);
            } else if (cmd == "population") {
                if (sign == '+') city.population += num;
                else city.population = max(0, city.population - num);
            }
            city.print();
        } 
        else if (cmd == "build") {
            string building;
            cin >> building;
            if (building == "factory") {
                if (!city.hasFactory) city.hasFactory = true;
            } else if (building == "market") {
                if (!city.hasMarket) city.hasMarket = true;
            }
            city.print();
        }
    }
    return 0;
}
