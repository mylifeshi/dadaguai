#include<iostream>
#include<iomanip>
using namespace std;
int a[10][10],b,c;
int main() {
	while (1) {
		cin >> b;
		if (b == -1)break;
		cin >> c;
		a[b + 1][c + 1]++; 
		a[b][c + 1]++;
		a[b + 1][c]++;
		a[b + 2][c+1]++;
		a[b + 1][c + 2]++;
		for (int i = 1; i <= 3; i++)for (int j = 1; j <= 3; j++)if (a[i][j] == 2)a[i][j] = 0;
	}
	cout << "最终的翻转结果是：" << endl;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}