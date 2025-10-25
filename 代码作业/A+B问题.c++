#include <iostream>
using namespace std;
int main() {
	long long a,b;
	cin >> a>>b;
	if (cin.good() == 0) {
		cout << "Wrong";
	}
	else cout << a + b;
	return 0;
}
