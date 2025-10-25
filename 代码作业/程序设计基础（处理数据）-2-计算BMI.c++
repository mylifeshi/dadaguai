#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	double n, m;
	cin >> n >> m;
	double BMI = m / ((n / 100) * (n / 100));
	BMI = BMI + 0.00001;
	cout << "此人BMI为"<<setprecision(6) << BMI << "。";
	return 0;
}