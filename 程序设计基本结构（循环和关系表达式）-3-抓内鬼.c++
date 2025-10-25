#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int a,ans;
int main() {
	cin >> a;
	while (cin.fail()!=1) {
		ans++;
		cin >> a;
	}
	cout << ans;
	return 0;
}