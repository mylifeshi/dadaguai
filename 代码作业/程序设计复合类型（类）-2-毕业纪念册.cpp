#include <iostream>
#include <iomanip>
using namespace std;

class StudentInfo {
    /****************** TODO ******************/
private:
    string name;
    string id;
    char gender;
    string zodiac;
    string hobbies;
    string message;
    string getChineseZodiac(const string &z) const {
        if (z == "Ari") return "白羊座";
        if (z == "Tau") return "金牛座";
        if (z == "Gem") return "双子座";
        if (z == "Cnc") return "巨蟹座";
        if (z == "Leo") return "狮子座";
        if (z == "Vir") return "处女座";
        if (z == "Lib") return "天秤座";
        if (z == "Sco") return "天蝎座";
        if (z == "Sgr") return "射手座";
        if (z == "Cap") return "摩羯座";
        if (z == "Agr") return "水瓶座";
        if (z == "Psc") return "双鱼座";
        return "无";
    }
    void readLine(string &s) {
        s.clear();
        char ch;
        while (cin.get(ch)) {
            if (ch == '\n') break;
            s.push_back(ch);
        }
        if (!s.empty() && s.back() == '\r') s.pop_back();
    }
    /**************** TODO-END ****************/

public:
    void inputStudentInfo();
    void printStudentInfo();
};

/****************** TODO ******************/
void StudentInfo::inputStudentInfo() {
    cin >> name;
    cin >> id;
    cin >> gender;
    cin >> zodiac;
    cin.ignore();
    readLine(hobbies);
    readLine(message);
    if (name.empty() || id.size() != 8 || (gender != 'M' && gender != 'F')) {
        cout << "输入错误";
        exit(0);
    }
    for (int i = 0; i < (int)id.size(); i++) {
        if (id[i] < '0' || id[i] > '9') {
            cout << "输入错误";
            exit(0);
        }
    }
    if (zodiac == "\\") zodiac = "";
    if (hobbies == "\\") hobbies = "";
    if (message == "\\") message = "";
}
void StudentInfo::printStudentInfo() {
    cout << "姓名：" << name << endl;
    cout << "学号：" << id << endl;
    cout << "性别：" << (gender == 'M' ? "男" : "女") << endl;
    cout << "星座：" << getChineseZodiac(zodiac) << endl;
    cout << "爱好：" << (hobbies.empty() ? "无" : hobbies) << endl;
    cout << "赠言：" << (message.empty() ? "无" : message) << endl;
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