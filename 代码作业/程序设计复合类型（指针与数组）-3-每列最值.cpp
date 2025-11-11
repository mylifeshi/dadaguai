#include <iostream>
#define ARRAY_ROWS 6
#define ARRAY_COLS 6
using namespace std;

void find_cols_max(int(*matrix)[ARRAY_COLS], int* cols_max)
{
    /****************** TODO ******************/
    // 想一想，int(*matrix)[ARRAY_COLS]是什么参数？
    // 二维数组还有哪些传递参数的方式？
    for(int col =0;col<ARRAY_COLS;++col){
        *(cols_max + col)=*(*(matrix)+col);
        for(int row =1;row<ARRAY_ROWS;++row){
            int val=*(*(matrix+row)+col);
            if(val>*(cols_max+col))*(cols_max+col)=val;
        }
    }
    /**************** TODO-END ****************/
}
void find_cols_min(int(*matrix)[ARRAY_COLS], int* cols_min)
{
    /****************** TODO ******************/
    for(int col=0;col<ARRAY_COLS;++col){
        *(cols_min+col)=*(*(matrix)+col);
        for(int row=1;row<ARRAY_ROWS;++row){
            int val =*(*(matrix+row)+col);
            if(val<*(cols_min+col))*(cols_min+col)=val;
        }
    }
    /**************** TODO-END ****************/
}

int main()
{
    int matrix[ARRAY_ROWS][ARRAY_COLS] = {};
    int cols_max[ARRAY_COLS] = {}; // 存放每一列的最大值
    int cols_min[ARRAY_COLS] = {}; // 存放每一列的最小值

    for (int i = 0; i < ARRAY_ROWS; ++i) {
        for (int j = 0; j < ARRAY_COLS; ++j)
            cin >> matrix[i][j];
    }

    find_cols_max(matrix, cols_max);
    find_cols_min(matrix, cols_min);

    cout << "Cols max: ";
    for (int i = 0; i < ARRAY_COLS; ++i) {
        cout << cols_max[i] << ' ';
    }
    cout << endl;

    cout << "Cols min: ";
    for (int i = 0; i < ARRAY_COLS; ++i) {
        cout << cols_min[i] << ' ';
    }
    cout << endl;
  
    return 0;
}