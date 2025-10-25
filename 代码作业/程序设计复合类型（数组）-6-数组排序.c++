#include<iostream>
using namespace std;
int a[100],temp;
int main() {
	for (int i = 1; i <= 20; i++)cin >> a[i];
	for (int i = 1; i <= 20; i++) {
		for (int j = 2; j <= 20; j++) {
			if (a[j] < a[j - 1]) {
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	cout << "升序排序后的结果：";
	for (int i = 1; i <= 20; i++)cout << a[i] << " ";
	return 0;
}