#include <iostream>
using namespace std;

void anticlockwise_print(int* array, int rows, int cols)
{
    /****************** TODO ******************/
    if (rows == 0 || cols == 0) return;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    bool first = true; 
    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; i++) {
            if (!first) cout << ' ';
            cout << array[i * cols + left];
            first = false;
        }
        left++;
        if (left > right) break;
        for (int j = left; j <= right; j++) cout << ' ' << array[bottom * cols + j];
        bottom--;
        if (top > bottom) break;
        for (int i = bottom; i >= top; i--) cout << ' ' << array[i * cols + right];
        right--;
        if (left > right) break;
        for (int j = right; j >= left; j--) cout << ' ' << array[top * cols + j];
        top++;
    }
    cout << endl;
    /**************** TODO-END ****************/
}

int main()
{
    const int max_rows = 20, max_cols = 20;
    int rows = 0, cols = 0;
    cin >> rows >> cols;

    // 用一维数组存储矩阵
    int array[max_rows * max_cols] = {};

    // 读取矩阵
    for (int i = 0; i < rows * cols; ++i) {
        cin >> array[i];
    }

    anticlockwise_print(array, rows, cols);

    return 0;
}