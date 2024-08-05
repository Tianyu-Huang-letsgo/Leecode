#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret_vec(n, vector<int>(n)); // 初始化 n x n 的矩阵
        int cnt = 1;
        int top = 0, left = 0, down = n - 1, right = n - 1;
        while (cnt <= n * n)
        { // 注意这里是 n * n，因为我们要填充 n*n 个元素
          // gpt给出的答案清晰太多，遍历行/列的时候，另一个维度应该是固定为边界。遍历完该行/列，应该更新对应边界。
            for (int j = left; j <= right && cnt <= n * n; j++)
            { // 从左到右填充顶部行
                ret_vec[top][j] = cnt++;
            }
            top++; // 完成顶部行，顶部边界下移

            for (int i = top; i <= down && cnt <= n * n; i++)
            { // 从上到下填充右侧列
                ret_vec[i][right] = cnt++;
            }
            right--; // 完成右侧列，右侧边界左移

            for (int j = right; j >= left && cnt <= n * n; j--)
            { // 从右到左填充底部行
                ret_vec[down][j] = cnt++;
            }
            down--; // 完成底部行，底部边界上移

            for (int i = down; i >= top && cnt <= n * n; i--)
            { // 从下到上填充左侧列
                ret_vec[i][left] = cnt++;
            }
            left++; // 完成左侧列，左侧边界右移
        }
        return ret_vec;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> ret = s->generateMatrix(16);
    return 0;
}