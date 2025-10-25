#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
double n,b=1;
double a=1;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		b = b * i;
		a = a + 1 / b;
	}
	cout << "估算值为" << fixed << setprecision(10) << a;
	return 0;
}