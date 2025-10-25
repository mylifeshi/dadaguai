#include <iostream>
// 实际上，这里使用枚举会比使用宏定义更好
#define INFO_MESSAGE 0
#define WARNING_MESSAGE 1
#define ERROR_MESSAGE 2
using namespace std;

/****************** TODO ******************/
void message(const string& content, int type = INFO_MESSAGE) {
    switch (type) {
    case INFO_MESSAGE:    cout << content;          break;
    case WARNING_MESSAGE: cout << "警告：" << content; break;
    case ERROR_MESSAGE:   cout << "错误：" << content; break;
    }
    cout << endl;
}
/**************** TODO-END ****************/

// 下面是一个使用你所编写函数的样例程序，它尝试将五级制绩点转换为百分制绩点
int main()
{
    double grade;

    message("请输入五级制绩点：");
    cin >> grade;

    if (cin.fail())
    {
        message("输入错误！你的输入不是数字！", ERROR_MESSAGE);
        return 0;
    }

    if (grade < 0 || grade > 5)
    {
        message("你的输入可能不符合规范。（五级制绩点取值一般在0-5）", WARNING_MESSAGE);
    }

    message("转换成功，百分制绩点是：", INFO_MESSAGE);
    // 思考：如果下面这行代码改为 message(grade * 10 + 45); ，你的程序应当如何修改？
    cout << grade * 10 + 45 << endl;

    return 0;
}