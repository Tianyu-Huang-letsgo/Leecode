#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 搜索二维矩阵
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        // 通过索引进行遍历
        int l = 0, rgt = r * c - 1;
        int ret = false;
        while (l <= rgt)
        {
            int m = (l + rgt) >> 1;
            int r_ind = m / c;
            int c_ind = m % c;

            if (matrix[r_ind][c_ind] < target)
            {
                l = m + 1;
            }
            else if (matrix[r_ind][c_ind] > target)
            {
                rgt = m - 1;
            }
            else
            {
                ret = true;
                break;
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 1}};
    Solution *s = new Solution();
    bool ret = s->searchMatrix(v, 2);
    return 0;
}