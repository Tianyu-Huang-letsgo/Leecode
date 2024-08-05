#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
    // 思路：
    // 1. 创建数组尺寸相同哈希表记录对应下标是否经过遍历
    // 2. 左上初始边界为0，右下初始边界为m-1,n-1，右下边界不断刷新
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> vec_ret;
        int left = 0;
        int up = 1;
        int right = m - 1;
        int button = n - 1;
        int i = 0;
        int j = 0;
        int cnt = 0;
        // for (int cnt = 0; cnt < n * m; cnt++)
        while (cnt < n * m)
        {
            while (j <= right && cnt < n * m)
            {
                vec_ret.push_back(matrix[i][j]);
                cnt++;
                j++;
            }
            j--;
            right--;
            i++;
            while (i <= button && cnt < n * m)
            {
                vec_ret.push_back(matrix[i][j]);
                cnt++;
                i++;
            }
            i--;
            button--;
            j--;
            while (j >= left && cnt < n * m)
            {
                vec_ret.push_back(matrix[i][j]);
                cnt++;
                j--;
            }
            j++;
            left++;
            i--;
            while (i >= up && cnt < n * m)
            {
                vec_ret.push_back(matrix[i][j]);
                cnt++;
                i--;
            }
            i++;
            up++;
            j++;
        }
        return vec_ret;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ret = s->spiralOrder(v);
    return 0;
}