#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int a,b;
int zs(int n) {
	if (n == 1)return 0;
	if (n == 2 || n == 3)return 1;
	for (int i = 2; i * i <= n; i++) if (n%i == 0)return 0;
	return 1;
}
int main() {
	cin >> a>>b;
	cout << "区间中的质数有：";
	for (int i = a; i <= b; i++) if (zs(i))cout << i<<" ";
	return 0;
}