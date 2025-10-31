#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
struct Farm {
    int hill = 0;
    int plain = 0;
    int floodplain = 0;
    int food() const {
        return hill * 2 + plain * 3 + floodplain * 4;
    }
};
struct Plantation {
    int fabric = 0; 
    int food = 0;   
    int gold() const { return fabric * 4; }
    int foodYield() const { return food * 4; }
};
struct Mine {
    int material = 0; 
    int precious = 0;
    int gold() const {
         return material * 2 + precious * 4;
}
    int hammer() const { 
        return material * 4 + precious * 2;
    }
};
struct City {
    string name;
    int population = 0;
    Farm farm;
    Plantation plantation;
    Mine mine;
    bool hasFactory = false;
    bool hasMarket = false;
    City() = default;
    City(const string& n, int p) : name(n), population(p) {}
    int food() const {
        return farm.food() + plantation.foodYield() - population * 2;
    }
    int gold() const {
        int r = plantation.gold() + mine.gold();
        if (hasMarket) r += population * 2;
        if (hasFactory) r -= 10;
        return r;
    }
    int hammer() const {
        int r = mine.hammer() + population;
        if (hasFactory) r += population * 2;
        return r;
    }
    void print() const {
        cout << name << " " << population << "人 "
             << (food() >= 0 ? "+" : "") << food() << "粮 "
             << (gold() >= 0 ? "+" : "") << gold() << "金 "
             << (hammer() >= 0 ? "+" : "") << hammer() << "锤" << endl;
    }
};
int PNFS(string token, stringstream &ss) {
    if (!token.empty() && (token[0] == '+' || token[0] == '-')) {
        if (token.size() > 1) {
            int val = 0;
            bool ok = true;
            for (size_t i = 1; i < token.size(); ++i) {
                if (token[i] < '0' || token[i] > '9') { ok = false; break; }
                val = val * 10 + (token[i] - '0');
            }
            if (!ok) return 0;
            return (token[0] == '+') ? val : -val;
        } else {
            string numToken;
            if (ss >> numToken) {
                int val = 0;
                bool ok = true;
                for (char c : numToken) {
                    if (c < '0' || c > '9') { 
                        ok = false;
                         break; 
                        }
                    val = val * 10 + (c - '0');
                }
                if (!ok) return 0;
                return (token[0] == '+') ? val : -val;
            } else {
                return 0;
            }
        }
    } else {
        bool ok = true;
        int val = 0;
        for (char c : token) {
            if (c < '0' || c > '9') { ok = false; break; }
            val = val * 10 + (c - '0');
        }
        if (!ok) return 0;
        return val;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    City city;
    string cityName;
    int pop;
    if (!(cin >> cityName >> pop)) return 0;
    city.name = cityName;
    city.population = pop;
    string line;
    getline(cin, line);
    while (true) {
        if (!getline(cin, line)) break;
        if (line == "quit") break;
        if (line.empty()) continue;
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "build") {
            string what;
            ss >> what;
            if (what == "factory") {
                if (!city.hasFactory) city.hasFactory = true;
            } else if (what == "market") {
                if (!city.hasMarket) city.hasMarket = true;
            }
            city.print();
            continue;
        }
        if (cmd == "population") {
            string signTok;
            if (!(ss >> signTok)) { city.print(); continue; }
            int delta =PNFS(signTok, ss);
            if (delta >= 0) city.population += delta;
            else {
                city.population += delta;
                if (city.population < 0) city.population = 0;
            }
            city.print();
            continue;
        }
        if (cmd == "farm" || cmd == "plantation" || cmd == "mine") {
            string type;
            if (!(ss >> type)) { city.print(); continue; }
            string signTok;
            if (!(ss >> signTok)) { city.print(); continue; }
            int delta = PNFS(signTok, ss);
            if (cmd == "farm") {
                int *target = nullptr;
                if (type == "hill") target = &city.farm.hill;
                else if (type == "plain") target = &city.farm.plain;
                else target = &city.farm.floodplain;
                *target += delta;
                if (*target < 0) *target = 0;
            } else if (cmd == "plantation") {
                int *target = nullptr;
                if (type == "fabric") target = &city.plantation.fabric;
                else target = &city.plantation.food;
                *target += delta;
                if (*target < 0) *target = 0;
            } else if (cmd == "mine") {
                int *target = nullptr;
                if (type == "material") target = &city.mine.material;
                else target = &city.mine.precious;
                *target += delta;
                if (*target < 0) *target = 0;
            }
            city.print();
            continue;
        }
        city.print();
    }
    return 0;
}
