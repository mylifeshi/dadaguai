#include<iostream>
#include<iomanip>
using namespace std;
int a[100][100],maxa[10][10];
int main() {
	for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) cin >> a[i][j];
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			maxa[i][j] = a[2 * i - 1][2 * j - 1];
			for (int k = 2 * i - 1; k <= 2 * i; k++) {
				for (int l = 2 * j - 1; l <= 2 * j; l++) {
					if (a[k][l] > maxa[i][j])maxa[i][j] = a[k][l];
				}
			}
		}
	}
	cout << "进行2*2最大池化的结果为："<<endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << maxa[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}