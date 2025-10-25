#include<iostream>
using namespace std;
int c,a[100], b[100],i,cw[100],s;
int tc(int k) {
	for (int j = 1; j < i; j++) {
		s = j;
	    if (a[j] == a[i])return 1;
	}
	return 0;
}
int main() {
	while (1) {
		i++;
		cin >> a[i] ;
		if (a[i] == -1)break;
		cin >> b[i];
		if (tc(a[i]))cout << "该车已经停在" << b[s] << "号车位了！"<<endl;
		else 
		if (cw[b[i]] == 0) {
			cw[b[i]] = a[i];
			cout << a[i] << "号车成功停靠在" << b[i] << "号车位！" << endl;
		}
		else cout << cw[b[i]] << "号车已经占据该车位了！"<<endl;
	}
	return 0;
}