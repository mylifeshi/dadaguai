#include<iostream>
using namespace std;
int main() {
	int n,a,b,c,s;
	cin >> n;
	a = (n-n%500)/500;
	s = n - a*500;
	b = (s - s % 50) / 50;
	s = s - b * 50;
	c = (s - s % 5) / 5;
	cout << a << "斤" << b << "两" << c << "钱";
	return 0;
}