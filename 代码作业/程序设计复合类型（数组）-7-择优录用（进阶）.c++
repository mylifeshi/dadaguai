#include<iostream>
#include<iomanip>
using namespace std;
double a,zd[100],zz;
int n;
int px(int) {
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (zd[j] < zd[j - 1]) {
				double temp = zd[j - 1];
				zd[j - 1] = zd[j];
				zd[j] = temp;
			}
		}
	}
	return 0;
}
int main() {
	while (1) {
		cin >> a;
		if (a == -1)break;
		if (n == 0 && a >= 3.5) {
			n++;
			zd[n]=a;
			zz += a;
			continue;
		}
		if (a > (zz / n)) {
			if (n < 10) {
				n++;
				zd[n] = a;
				zz += a;
				px(0);
			}
			else {
				zz = zz - zd[1];
				zd[1] = a;
				zz += a;
				px(0);
			}
			continue;
		}
	}
	cout << "最终被录取绩点情况：" << endl;
	for (int i = n; i >= 1; i--)cout <<fixed<<setprecision(2)<< zd[i] << " ";
	cout << endl << "平均绩点：" << endl;
	double k = 0;
	if (zz == 0)cout << fixed<<setprecision(2)<<k;
	else cout << zz / n;
	return 0;
}