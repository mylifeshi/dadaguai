#include<iostream>
using namespace std;
char a, b, c;
double d;
int main() {
	cin >> a >> b >> c >> d;
	cout << "这个瓜是";
	if (a == 'W')cout << "坏瓜";
	else if (a == 'B') {
		if (d < 0.4)cout << "好瓜";
		else cout << "坏瓜";
	}
	else {
		if (b == 'M')cout << "好瓜";
		else if (c == 'S')cout << "坏瓜";
		else cout << "好瓜";
	}
	cout << "。";
	return 0;
}