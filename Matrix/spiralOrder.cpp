#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
    // 思路一定要清晰，走过一段是那个方向边界发生变化
    // 边界条件非常巧妙，如果上下夹层或者左右夹层，说明没有数字（空间）继续遍历了，已经遍历完了
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int u = 0, l = 0;
        int r = matrix[0].size() - 1;
        int d = matrix.size() - 1;
        vector<int> ret;
        while (true)
        {
            // 向右
            for (int i = l; i <= r; ++i)
            {
                ret.push_back(matrix[u][i]);
            };
            if (++u > d)
                break;

            // 向下
            for (int i = u; i <= d; ++i)
            {
                ret.push_back(matrix[i][r]);
            }
            if (--r < l)
                break;

            // 向左
            for (int i = r; i >= l; --i)
            {
                ret.push_back(matrix[d][i]);
            }
            if (--d < u)
                break;

            // 向上
            for (int i = d; i >= u; --i)
            {
                ret.push_back(matrix[i][l]);
            }
            if (++l > r)
                break;
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v = {{2, 5, 8}, {4, 0, -1}};
    Solution *s = new Solution();
    vector<int> ret = s->spiralOrder(v);
    return 0;
}