#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 柱状图中最大的矩形
// 找左端、右端小于自身的值，其包裹的元素就是可以计算的面积，进行计算，典型单调栈-递减
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int ret = 0;
        st.push(-1); // 解题核心1：-1作为哨兵值用于存放一个假想的最小值0，使得每个值都有一个确定的左值(栈永不为空)
        for (int i = 0; i < heights.size(); i++)
        {
            // 使用st.top != -1作为原先非空数组的判断
            while (st.top() != -1 && heights[st.top()] >= heights[i]) // 这里=也归到<，这个值存进去，结果只会大不会小
            {
                int cur_h = heights[st.top()];
                st.pop();
                int area = cur_h * (i - st.top() - 1); // 即使st.top()是-1，结果也是正确的
                ret = max(ret, area);
            }
            st.push(i);
        }
        while (st.top() != -1) // 栈有剩余值说明这些值没有找到合适的右值（不然早就pop出去了）
        {
            int cur_h = heights[st.top()];
            st.pop();
            // 合理性分析： 这些值都是递减的，最右端的0就可以充当它们的右值，左值在栈中是一直存放着的
            int area = cur_h * (heights.size() - st.top() - 1); // 这里的heights.size()其实也是类似于-1的一个越界下标
            ret = max(ret, area);
        }
        return ret;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {2, 1, 5, 6, 2, 3};
    int ret = s->largestRectangleArea(v);
    return 0;
}