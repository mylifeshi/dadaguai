#include <iostream>
#include <string.h>
using namespace std;

/****************** TODO ******************/
string& xor_str(string& str1, const string& str2)
{
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t maxlen = max(len1, len2);
    string res(maxlen, '0');
    for (int i = 0; i < maxlen; i++)
    {
        char a = (i < maxlen - len1) ? '0' : str1[i - (maxlen - len1)];
        char b = (i < maxlen - len2) ? '0' : str2[i - (maxlen - len2)];
        res[i] = (a == b ? '0' : '1');
    }
    str1 = res;
    return str1; 
}
/**************** TODO-END ****************/

int main()
{
	string dst, src;
	cin >> dst >> src;

	xor_str(dst, src); // dst = dst ⊕ src
	cout << dst << endl;

	// 链式异或操作
	xor_str(xor_str(dst, src), src); // dst = dst ⊕ src ⊕ src
	cout << dst << endl;
	// 链式异或操作
	xor_str(dst, src) += src; // dst = dst ⊕ src + src
	cout << dst << endl;

	cout << src << endl;

	return 0;
}