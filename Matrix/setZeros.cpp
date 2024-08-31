#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

// 矩阵置零
class Solution
{
public:
    // 难点：使用常量空间进行解题
    // 思路：使用集合记录为0的行/列，再对原二维数组进行遍历
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> row;
        unordered_set<int> col;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int r : row)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[r][i] = 0;
            }
        }
        for (int c : col)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][c] = 0;
            }
        }
    }
};

int main()
{

    return 0;
}