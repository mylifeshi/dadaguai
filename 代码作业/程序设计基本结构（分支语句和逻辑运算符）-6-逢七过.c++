#include<iostream>
#include <cmath>
using namespace std;
int a, b,ans,s;
int main() {
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		int k = i;
		for (int j = 5; j >= 1; j--) {
			int q = pow(10, j);
			if (k < q)continue;
			if ((k-k%q)/q == 7) {
				ans++;
				s = 1;
				cout << i << " ";
				break;
			}
			else {
				k = k % q;
				if (k == 7) {
					ans++;
					s = 1;
					cout << i << " ";
					break;
				}
			}
		}
		if (s == 0 && i % 7 == 0) {
			ans++;
			cout << i << " ";
		}
		s = 0;
	}
	cout << "一共有" << ans << "个数字需要说“过”";
	return 0;
}