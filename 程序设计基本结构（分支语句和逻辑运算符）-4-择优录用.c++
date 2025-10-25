#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
double n, a, b;
int main() {
	cin >> n;
	while (n != -1) {
		if(a==10)cout << fixed << setprecision(2) << n << "未被录用。" << endl;
		else if (a == 0) {
			cout << fixed << setprecision(2) << n << "被录用了。" << endl;
			a++;
			b = b + n;
		}
		else if (n > (b / a)) {
			a++;
			b = b + n;
			cout << fixed << setprecision(2) << n << "被录用了。" << endl;
		}
		else cout << fixed << setprecision(2) << n << "未被录用。" << endl;
		cin >> n;
	}
	return 0;
}