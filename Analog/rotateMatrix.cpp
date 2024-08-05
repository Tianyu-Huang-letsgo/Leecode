#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 设矩阵行列数为 n
        int n = matrix.size();
        // 起始点范围为 0 <= i < n / 2 , 0 <= j < (n + 1) / 2         当n为奇数时，要补上中间的元素
        // 其中 '/' 为整数除法
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                // 暂存 A 至 tmp
                int tmp = matrix[i][j];
                // 元素旋转操作 A <- D <- C <- B <- tmp
                matrix[i][j] = matrix[n - 1 - j][i]; // 核心：行的反数（n-1-i）转成列，列转成行
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> ret;
    return 0;
}