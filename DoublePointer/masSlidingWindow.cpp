#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 思路：
        // 1. 滑动窗口可以从j=0,i<0开始滑
        // 2. deque记录为非严格递减序列
        // 3. j引入的值如果比较大，那deque中小于nums[j]的值都可以舍去，因为当j在滑动窗口中，最大值不会比nums[j]更小；
        // 4. 当j引入的值比较小，也要存到deque中，因为之后的值可能更小，迟早会轮到j作为窗口最大值。
        if (nums.size() == 0 || k == 0)
            return {};
        deque<int> deque;
        vector<int> res(nums.size() - k + 1);
        for (int j = 0, i = 1 - k; j < nums.size(); i++, j++)
        {
            // 删除 deque 中对应的 nums[i-1]
            if (i > 0 && deque.front() == nums[i - 1])
                deque.pop_front();
            // 保持 deque 递减
            while (!deque.empty() && deque.back() < nums[j])
                deque.pop_back();
            deque.push_back(nums[j]);
            // 记录窗口最大值
            if (i >= 0)
                res[i] = deque.front();
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {1, 2, 1, 1, 3, 3, 3, 8, 8, 8};
    vector<int> v2 = {9, 10, 9, -7, -4, -8, 2, -6};

    vector<int> ret = s->maxSlidingWindow(v2, 5);
    return 0;
}