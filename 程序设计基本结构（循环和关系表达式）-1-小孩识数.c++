#include<iostream>
using namespace std;
int main() {
	int n,a,ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ans = ans + a;
	}
	cout << "这" << n << "个数的求和结果为" << ans << "。";
	return 0;
}