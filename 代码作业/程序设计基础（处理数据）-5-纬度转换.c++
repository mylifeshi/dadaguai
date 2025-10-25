#include<iostream>
using namespace std;
int main() {
	double a, b, c, d ;
	cin >> a >> b >> c;
	d = a + b / 60 + c / 3600;
	cout << a << "度" << b << "分" << c << "秒相当于" << d << "度。";
	return 0;
}