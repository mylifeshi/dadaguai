#include <iostream>
#include <string>
using namespace std;
class City {
private:
    string name;
    int population;
    int farm;
    bool hasCampus;
public:
    City(string n, int p, int f)
        : name(n), population(p), farm(f), hasCampus(false) {}

    void buildCampus() {
        if (!hasCampus) hasCampus = true;
    }
    void changeFarm(int n) {
        farm += n;
        if (farm < 0) farm = 0;
    }
    void changePopulation(int n) {
        population += n;
        if (population < 0) population = 0;
    }
    int food() const {
        return farm * 4 - population * 2;
    }
    int tech() const {
        return hasCampus ? 4 : 0;
    }
    void print() const {
        cout << name << " " << population << " " << food() << " " << tech() << endl;
    }
};
int main() {
    string name;
    int population, farm;
    cin >> name >> population >> farm;
    City city(name, population, farm);
    string cmd;
    while (cin >> cmd) {
        if (cmd == "quit") break;

        if (cmd == "farm") {
            char op;
            int n;
            cin >> op >> n;
            if (op == '+') city.changeFarm(n);
            else if (op == '-') city.changeFarm(-n);
        } 
        else if (cmd == "population") {
            char op;
            int n;
            cin >> op >> n;
            if (op == '+') city.changePopulation(n);
            else if (op == '-') city.changePopulation(-n);
        } 
        else if (cmd == "build") {
            string what;
            cin >> what;
            if (what == "campus") city.buildCampus();
        }

        city.print();
    }
    return 0;
}
