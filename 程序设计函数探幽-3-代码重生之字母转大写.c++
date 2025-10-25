#include <iostream>
#include <cstring>
#define STRING_MAX_LENGTH 200
using namespace std;

/****************** TODO ******************/
int to_upper(char a[]) {
    size_t len = strlen(a);
    int n = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] >= 97 && a[i] <= 122) {
            a[i] -= 32;
            n++;
        }
    }
    return n;
}
/**************** TODO-END ****************/

int main()
{
    char str[STRING_MAX_LENGTH];
    cin.getline(str, STRING_MAX_LENGTH);

    int num = to_upper(str);
    // 想一想，字符串内容改变了吗？为什么？

    cout << "共转换" << num << "个字母。" << endl;
    cout << str << endl;

    return 0;
}