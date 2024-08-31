#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 搜索二维矩阵Ⅱ
class Solution
{
public:
    // 在小四方块中，左上角元素最小，右下角最大，左下角/左上角介于二者间
    // 引出四个子区间问题
    // 应该是不断搜索，直至走出边界未搜索到返回false
    // 有可能出现相同元素
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        bool ret = search(matrix, target, 0, m - 1, 0, n - 1);
        return ret;
    }

private:
    bool search(vector<vector<int>> &matrix, const int target, int t, int b, int l, int r)
    {
        int i = t, j = l; // 初始化左上角坐标
        while (i >= t && j >= l && i <= b && j <= r)
        {
            if (matrix[i][j] < target)
            {
                if (i + 1 > b && j + 1 > r)
                {
                    return false;
                }
                if (i + 1 <= b)
                {
                    ++i;
                }
                if (j + 1 <= r)
                {
                    ++j;
                }
            }
            else if (matrix[i][j] == target)
            {
                return true;
            }
            else
            {
                return search(matrix, target, t, i - 1, j, r) || search(matrix, target, i, b, l, j - 1); // 当前要找的值比左上角的大，比当前的要小。进入左下、右上搜索
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}