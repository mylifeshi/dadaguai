#include<iostream>
#include<iomanip>
using namespace std;
int n;
double a, b,c,d;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		c = c + a * b;
		d = d + a;
		cout << "当前均绩为";
        cout << fixed << setprecision(2) << c / d<<"。"<<endl;
	}
	return 0;
}