#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int g[100][100],a[100], b[100], c[100],tem,flag;
int gy(int x, int y,int n) {
	if (x == 0 || x == 10 || y == 0 || y == 10)return 1;
	if (n == 0)return 1;
	if (n > g[x][y])g[x][y] = n;
	gy(x - 1, y, n - 1);
	gy(x + 1, y, n - 1);
	gy(x, y + 1, n - 1);
	gy(x, y - 1, n - 1);
	return 1;
}
int main() {
	while (1) {
		tem++;
		cin >> a[tem];
		if (a[tem] == -1)break;
		cin >> b[tem] >> c[tem];
		gy(a[tem]+1, b[tem]+1, c[tem]);
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k < tem; k++) {
				if (i == a[k] + 1 && j == b[k] + 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)cout << '*' << " ";
			else cout << g[i][j] << " ";
			flag = 0;
		}
		cout << endl;
	}
	return 0;
}