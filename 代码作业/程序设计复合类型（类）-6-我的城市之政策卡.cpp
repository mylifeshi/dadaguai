#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class City {
private:
    string name;
    int population;
    int farm;
    bool hasCampus;
    bool hasLibrary;
    bool hasUniversity;
    bool hasLab;
    char policy; 
public:
    City(string n, int p, int f)
        : name(n), population(p), farm(f),
          hasCampus(false), hasLibrary(false),
          hasUniversity(false), hasLab(false), policy(0) {}
    void changeFarm(int delta) {
        farm += delta;
        if (farm < 0) farm = 0;
    }
    void cp(int delta) {
        population += delta;
        if (population < 0) population = 0;
    }
    void build(const string &what) {
        if (what == "campus") {
            hasCampus = true;
            return;
        }
        if (what == "library") {
            if (hasCampus && !hasLibrary) hasLibrary = true;
            return;
        }
        if (what == "university") {
            if (hasCampus && hasLibrary && !hasUniversity) hasUniversity = true;
            return;
        }
        if (what == "lab") {
            if (hasCampus && hasLibrary && hasUniversity && !hasLab) hasLab = true;
            return;
        }
    }
    void setPolicy(char c) {
        policy = c;
    }
    int food() const {
        return farm * 4 - population * 2;
    }
    double baseTech() const {
        double t = 0;
        if (hasCampus) t += 4;
        if (hasLibrary) t += 4 + population * 0.5;
        if (hasUniversity) t += 8 + population * 1.0;
        if (hasLab) {
            t += 16 + population * 1.0;
            if (population > 10) t += (population - 10) * 2.0;
        }
        return t;
    }
    double tech() const {
        double t = baseTech();
        int f = food();
        if (policy == 'A') {
            int count = 0;
            if (hasLibrary) count++;
            if (hasUniversity) count++;
            if (hasLab) count++;
            t += count * 10;
        } else if (policy == 'B') {
            t += population * 2;
        } else if (policy == 'C') {
            if (f > 0) t += f;
        }
        return t;
    }
    void print() const {
        cout << name << " " << population << " " << food() << " ";
        cout << fixed << setprecision(0) << tech() << "\n"; // 输出为整数，无小数点
        cout.unsetf(ios::fixed);
    }
};
int pt(const string &tok, stringstream &ss) {
    if (!tok.empty() && (tok[0] == '+' || tok[0] == '-')) {
        if (tok.size() > 1) {
            return stoi(tok);
        } else {
            int num = 0;
            if (ss >> num) return (tok[0] == '+') ? num : -num;
            return 0;
        }
    } else {
        return stoi(tok);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string name;
    int pop, f;
    if (!(cin >> name >> pop >> f)) return 0;
    string dummy;
    getline(cin, dummy);
    City city(name, pop, f);
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line == "quit") break;
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if (cmd == "farm") {
            string tok; ss >> tok;
            int delta = pt(tok, ss);
            city.changeFarm(delta);
        } else if (cmd == "population") {
            string tok; ss >> tok;
            int delta = pt(tok, ss);
            city.cp(delta);
        } else if (cmd == "build") {
            string what; ss >> what;
            city.build(what);
        } else if (cmd == "set") {
            char c; ss >> c;
            city.setPolicy(c);
        }
        city.print();
    }
    return 0;
}
