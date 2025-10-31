#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
private:
    char name[100];
    char major[100];
    int year;
    double gpa;
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/
void StudentInfo::inputStudentInfo() {
    cin.getline(name, 100);
    cin.getline(major, 100);
    cin >> year >> gpa;
}

void StudentInfo::printStudentInfo() {
    cout << "学生信息：" << endl;
    cout << "姓名：" << name << endl;
    cout << "专业：" << major << endl;
    cout << "入学年份：" << year << endl;
    cout << fixed << setprecision(2);
    cout << "平均绩点：" << gpa << endl;
}
/**************** TODO-END ****************/

int main()
{
    StudentInfo student;
    // 输入学生信息
    student.inputStudentInfo();
    // 输出学生信息
    student.printStudentInfo();

    return 0;
}