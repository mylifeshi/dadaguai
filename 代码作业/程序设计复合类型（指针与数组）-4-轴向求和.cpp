#include <iostream>
using namespace std;

void sum(int* matrix, int axis, int* answer)
{
    /****************** TODO ******************/
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)*(answer+i*3+j)=0;
    if (axis == 0) for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)for (int k = 0; k < 3; ++k)*(answer + i * 3 + j) += *(matrix + k * 9 + i * 3 + j);
    else if (axis == 1) for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)for (int k = 0; k < 3; ++k)*(answer + i * 3 + j) += *(matrix + i * 9 + k * 3 + j);
    else if (axis == 2) for (int i = 0; i < 3; ++i)for (int j = 0; j < 3; ++j)for (int k = 0; k < 3; ++k)*(answer + i * 3 + j) += *(matrix + i * 9 + j * 3 + k);
    /**************** TODO-END ****************/
}

int main()
{
    int arr[3][3][3] = {};
    int answer[3][3] = {};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int axis = 0; axis < 3; ++axis)
    {
		sum(arr[0][0], axis, answer[0]);
		// 输出沿着 axis 轴向求和的结果
		cout << "axis = " << axis << endl;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << answer[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}