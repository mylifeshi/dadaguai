#include <iostream>
#include <iomanip>
using namespace std;

struct StudentInfo {
    // 回想一下，static和const的作用是什么？
    static const int MAX_NAME_LEN = 20;
    static const int MAX_MAJOR_LEN = 30;

    char name[MAX_NAME_LEN] = {}; // 学生姓名
    char major[MAX_MAJOR_LEN] = {}; // 专业
    int year = 0; // 入学年份
    double score = 0.0; // 平均绩点
};

void sort_info(StudentInfo* info_list, int info_num, char key)
{
    /****************** TODO ******************/
    for (int i = 0; i < info_num - 1; i++) {
        for (int j = i + 1; j < info_num; j++) {
            bool f = false;
            if (key == 'y' && info_list[i].year < info_list[j].year) f = true;
            if (key == 's' && info_list[i].score < info_list[j].score) f = true;
            if (f) {
                StudentInfo t = info_list[i];
                info_list[i] = info_list[j];
                info_list[j] = t;
            }
        }
    }
    /**************** TODO-END ****************/
}

void print_info(const StudentInfo* info_list, int info_num)
{
    /****************** TODO ******************/
       for (int i = 0; i < info_num; i++) {
        cout << info_list[i].name << " "
             << info_list[i].major << " "
             << info_list[i].year << " "
             << fixed << setprecision(2) << info_list[i].score << endl;
    }
    /**************** TODO-END ****************/
}

int main()
{
    StudentInfo info_list[10];

    for (int i = 0; i < 10; ++i)
    {
        cin >> info_list[i].name 
            >> info_list[i].major 
            >> info_list[i].year 
            >> info_list[i].score;
    }

    // 排序关键字，'y'表示按入学年份排序，'s'表示按平均绩点排序
    char key;
    cin >> key;

    // 调用排序函数，按照key的值进行排序
    sort_info(info_list, 10, key);
    // 输出排序后的结果
    print_info(info_list, 10);

    return 0;
}