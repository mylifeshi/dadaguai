#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
long long n,a,b,c;
int main() {
	cin >> n;
	a = 1, b = 1;
	if (n == 1 || n == 2)cout << 1;
	for (int i = 3; i <= n; i++) {
		c = a + b;
		a = b, b = c;
	}
	cout << "斐波那契数列中第" << n << "项的值为" << c << "。";
	return 0;
}