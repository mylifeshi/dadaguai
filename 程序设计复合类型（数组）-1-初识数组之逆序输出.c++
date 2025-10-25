#include<iostream>
using namespace std;
int str[100];
int main() {
	for (int i = 1; i <= 10; i++) cin >> str[i];
	for (int i = 10; i >= 1; i--)cout << str[i]<<" ";
	return 0;
}