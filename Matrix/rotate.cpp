#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

// 旋转图像
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                // 核心：列变行，行反数变列
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};

int main()
{
    return 0;
}