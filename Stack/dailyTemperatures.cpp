#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 每日温度
// 寻找右侧最大值，典型单调栈-递增
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        st.push(0);
        vector<int> ret(temperatures.size(), 0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i] <= temperatures[st.top()]) // 当前元素与栈顶元素相等或小于，直接入栈
            {
                st.push(i);
                continue;
            }
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) // 这个while是保持栈st单调性的保障
            {
                ret[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};

int main()
{
    return 0;
}