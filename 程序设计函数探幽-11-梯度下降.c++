#include <iostream>
#include <iomanip>
#define SAMPLE_LENGTH 10
#define DATA_NUM 4
#define PARAMS_NUM 4
#define MAX_ITERATION 128
using namespace std;

/****************** TODO ******************/
double mean_square_error(int d[SAMPLE_LENGTH][DATA_NUM], double pa[PARAMS_NUM]) {
    double s = 0.0;
    for (int i = 0; i < SAMPLE_LENGTH; ++i) {
        double p = 0.0;
        for (int j = 0; j < 3; ++j) p += pa[j] * d[i][j];
        p += pa[3];
        double e = p - d[i][3];
        s += e * e;
    }
    return s / SAMPLE_LENGTH;
}
void update_params(int d[SAMPLE_LENGTH][DATA_NUM], double pa[PARAMS_NUM]) {
    double g[4] = { 0.0 };
    for (int i = 0; i < SAMPLE_LENGTH; ++i) {
        double p = 0.0;
        for (int j = 0; j < 3; ++j) p += pa[j] * d[i][j];
        p += pa[3];
        double e = p - d[i][3];
        for (int j = 0; j < 3; ++j) g[j] += 2 * e * d[i][j];
        g[3] += 2 * e;
    }
    for (int j = 0; j < 4; ++j) pa[j] -= 0.01 * g[j] / SAMPLE_LENGTH;
}
/**************** TODO-END ****************/

int main()
{
    int data[SAMPLE_LENGTH][DATA_NUM] = {};

    // 输入训练数据
    for (int i = 0; i < SAMPLE_LENGTH; ++i)
    {
        for (int j = 0; j < DATA_NUM; ++j)
        {
            cin >> data[i][j];
        }
    }

    // 1. 参数初始化
    double params[PARAMS_NUM] = {};
    // 四个参数初始化为零，从前往后分别是w1,w2,w3,b

    // 进行迭代
    double loss = 0;
    cout << "Start Iteration!" << endl;
    cout << fixed << setprecision(6);
    for (int i = 0; i < MAX_ITERATION; ++i)
    {
        // 2. 使用当前参数和数据，计算损失函数
        loss = mean_square_error(data, params);
        // i 固定三位宽度输出，loss 固定六位小数位数输出
        cout << "iter: " << setw(3) << i << ", loss: ";
        cout << loss << endl;

        // 3. 计算梯度，使用梯度下降的方法更新参数
        update_params(data, params);
    }
    cout << "Iteration Finished!" << endl;

    // 输出回归后的参数值：
    cout << "params:" << endl;
    for (int i = 0; i < PARAMS_NUM; ++i)
    {
        cout << params[i] << endl;
    }

    return 0;
}