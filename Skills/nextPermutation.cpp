#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 31. 下一个排列
// 如果数组本身就是倒序，直接返回正序数组
class Solution
{
public:
    // 思路：从数组末端开始遍历，如果后数比前数大，进行交换
    // 使用单调栈，寻找第一个比遍历值大的值
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return;
        }
        int ptr = nums.size() - 1;
        vector<int> st;
        st.push_back(ptr);
        --ptr;
        while (ptr >= 0 && nums[ptr] >= nums[st.back()])
        {
            st.push_back(ptr);
            --ptr;
        }

        if (ptr < 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int ret_ind;
        while (!st.empty() && nums[ptr] < nums[st.back()])
        {
            ret_ind = st.back();
            st.pop_back();
        }
        swap(nums[ptr], nums[ret_ind]);
        sort(nums.begin() + ptr + 1, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution *s = new Solution();
    s->nextPermutation(nums);
    return 0;
}