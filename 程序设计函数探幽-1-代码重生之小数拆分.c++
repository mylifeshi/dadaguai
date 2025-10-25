#include <iostream>
using namespace std;

/****************** TODO ******************/
int integer(double a) {
    return (int)a;
}
double decimal(double a) {
    int b = (int)a;          
    double c = a - b;        
    if (c < 1e-6) c = 0;     
    return c;
}
/**************** TODO-END ****************/

int main()
{
	double num = 0;
  
    cin >> num;
    cout << "整数部分是" << integer(num) 
         << "，小数部分是" << decimal(num) << "。" << endl;

	return 0;
}