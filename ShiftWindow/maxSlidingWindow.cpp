#include <deque>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

// 滑动窗口最大值
// 因为需要滑动弹出front()值，不能用单调栈，只能使用单调队列
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 思路：
        // 1. 滑动窗口可以从j=0,i<0开始滑
        // 2. 临时窗口记录为非严格递减序列
        // 3. j引入的值如果比较大，那deque中小于nums[j]的值都可以舍去，因为当j在滑动窗口中，最大值不会比nums[j]更小；
        // 4. 当j引入的值比较小，也要存到deque中，因为之后的值可能更小，迟早会轮到j作为窗口最大值。
        if (nums.size() == 0 || k == 0)
            return {};
        deque<int> deque;
        vector<int> res(nums.size() - k + 1);
        // 越界滑动窗口，需要增加一些i>=0的判断条件进行相应的操作
        for (int j = 0, i = 1 - k; j < nums.size(); i++, j++) // 滑动窗口移位模板
        {
            // 删除 deque 中对应的 nums[i-1]
            if (i > 0 && deque.front() == nums[i - 1])
                deque.pop_front();
            // 保持 deque 递减,保证了dequie第一个值最大
            while (!deque.empty() && deque.back() < nums[j]) // 比back()小的值可以存进deque是因为头部元素总有弹出的一天
                deque.pop_back();
            deque.push_back(nums[j]);
            // 记录窗口最大值
            if (i >= 0)
                res[i] = deque.front();
        }
        return res;
    }
};