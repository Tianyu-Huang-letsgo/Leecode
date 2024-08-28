#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 移动零
class Solution
{
public:
    // 要求：尽量减少操作次数，在原数组进行操作
    // 思路：指针一直指向第一个0，遇到非零数进行交换，同时记录有几个连续零(有点类似于冒泡排序的步骤)
    void moveZeroes(vector<int> &nums)
    {
        int j = -1; // 指向第一个0
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) // 如果遍历到当前值是零
            {
                if (j == -1) // 且j未被指定，刷新j值
                {
                    j = i;
                }
                continue;
            }
            // 如果遍历到非零且j已被赋值，进行零交换
            if (j != -1)
            {
                nums[j] = nums[i];
                nums[i] = 0;
                if (j + 1 < nums.size() && nums[j + 1] == 0)
                {
                    j = j + 1;
                }
                else
                {
                    j = -1;
                }
            }
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {0, 1, 0, 3, 12};
    s->moveZeroes(v);
    return 0;
}