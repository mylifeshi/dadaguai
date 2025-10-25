#include <iostream>
using namespace std;
double C, F;
int wdzh(int) {
	F = 1.8 * C + 32.0;
	return 0;
}
int main() {
	cin >> C;
	wdzh(0);
	cout << "摄氏温度" << C << "度对应华氏温度" << F << "度。" << endl;
	return 0;
}