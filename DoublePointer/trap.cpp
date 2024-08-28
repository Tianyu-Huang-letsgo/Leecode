#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 接雨水
// 单调栈
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st; // 最小单调栈，找当前元素的左右最大值，递增
        st.push(0);    // 先将第一个值索引入栈
        int ret = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] <= height[st.top()]) // 若当前元素更小，入栈（这里等于入栈也不会影响，因为面积计算一样为0）
            {
                st.push(i);
                continue;
            }
            while (!st.empty() && height[i] > height[st.top()]) // 当栈非空且当前值大于栈顶值，需要进行面积计算
            {
                int cur_h = height[st.top()];
                st.pop();        // 弹出当前值（栈顶）
                if (!st.empty()) // 如果弹出当前值后st为空，说明没有值比弹出的值要大，不能构成积水
                {
                    ret += (min(height[st.top()], height[i]) - cur_h) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution *s = new Solution();
    int ret = s->trap(v);
    return 0;
}