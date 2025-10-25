#include<iostream>
using namespace std;
int n,a[1000];
int zs(int n) {
	if (n == 1||n==0)return 0;
	if (n == 2 || n == 3)return 1;
	for (int i = 2; i * i <= n; i++) if (n % i == 0)return 0;
	return 1;
}
int main() {
	while (1) {
		cin >> n;
		if (n == -1)break;
		if (n == 1) {
			for (int i = 2; i <= 99; i++) {
				if (zs(i))a[i]++;
				if (a[i] == 3)a[i] = 0;
			}
		}
		if (n == 2) {
			for (int i = 2; i <= 99; i++) {
				if (!zs(i))a[i]++;
				if (a[i] == 3)a[i] = 0;
			}
		}
		if (n == 3) {
			for (int i = 0; i <= 99; i++) {
				if (i % 2 == 1)a[i]++;
				if (a[i] == 3)a[i] = 0;
			}
		}
		if (n == 4) {
			for (int i = 0; i <= 99; i++) {
				if (i % 2 == 0)a[i]++;
				if (a[i] == 3)a[i] = 0;
			}
		}
	}
	cout << "熄灭：";
	for (int i = 0; i <= 99; i++)if (a[i] == 0)cout << i << " ";
	cout << endl<<"长亮：";
	for (int i = 0; i <= 99; i++)if (a[i] == 1)cout << i << " ";
	cout << endl << "闪烁：";
	for (int i = 0; i <= 99; i++)if (a[i] == 2)cout << i << " ";
	cout << endl;
	return 0;
}