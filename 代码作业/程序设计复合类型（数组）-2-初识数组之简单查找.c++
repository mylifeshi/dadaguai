#include<iostream>
using namespace std;
int str[100];
int a;
int cz(int k) {
	for (int i = 1; i <= 10; i++)if (str[i] == k)return 1;
	return 0;
}
int main() {
	for (int i = 1; i <= 10; i++) cin >> str[i];
	while (1 ) {
		cin >> a;
		if (a == -1)break;
		cout << a;
		if (cz(a))cout << "在数组中。"<<endl;
		else cout << "不在数组中。"<<endl;
	}
	return 0;
}