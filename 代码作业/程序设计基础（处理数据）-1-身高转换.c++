#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	double n;
	cin>> n;
	n = n / 100;
	cout <<"转换后的身高为" << /*setprecision(2) <<*/ n << "米。" << endl;
	return 0;
}