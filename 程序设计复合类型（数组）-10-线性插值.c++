#include<iostream>
#include<iomanip>
using namespace std;
int a[100][100];
int main() {
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) cin >> a[2 * i - 1][2 * j - 1];
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 2; j++) {
			a[2*i-1][2 * j] = (a[2*i-1][2 * j - 1] + a[2*i-1][2 * j + 1]) / 2;
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 3; j++) {
			a[2 * i][2 * j - 1] = (a[2 * i - 1][2 * j - 1] + a[2 * i + 1][2 * j - 1]) / 2;
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			a[2 * i][2 * j] = (a[2 * i-1][2 * j - 1] + a[2 * i-1][2 * j + 1] + a[2 * i +1][2 * j-1] + a[2 * i + 1][2 * j+1]) / 4;
		}
	}
	cout << "进行简单插值后的结果为：" << endl;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}