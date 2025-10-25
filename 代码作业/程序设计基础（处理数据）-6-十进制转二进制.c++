#include<iostream>
using namespace std;
int n, ans;
char a[8];
int main() {
	cin >> n;
	for (int i = 1; i <= 8; i++) {
		if (n == 0)break;
		if (n % 2 == 0)a[i] = '0';
		else a[i] = '1';
		n = n / 2;
		ans++;
	}
	for (int i = 8 - ans; i >= 1; i--)cout << '0';
	for (int i = ans; i >= 1; i--)cout << a[i];
	return 0;
}