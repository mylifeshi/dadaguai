#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int n,a;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				a++;
				cout << a << " ";
			}
			else cout << "0" << " ";
		}
		cout << endl;
	}
	return 0;
}