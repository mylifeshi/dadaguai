#include<iostream>
using namespace std;
int c,a[10], b[10];
int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> c;
			a[i] += c;
			b[j] += c;
		}
	}
	cout << "每一行元素的和：";
	for (int i = 1; i <= 4; i++)cout << a[i] << " ";
	cout << endl<<"每一列元素的和：";
	for (int i = 1; i <= 4; i++)cout << b[i] << " ";
	return 0;
}