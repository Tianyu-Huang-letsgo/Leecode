#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        // 思路，popped的下一个元素只能是pushed的前一个或者后一个元素
        class Solution
        {
        public:
            bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
            {
                stack<int> stk;
                int i = 0;
                for (int num : pushed)
                {
                    stk.push(num); // num 入栈
                    while (!stk.empty() && stk.top() == popped[i])
                    { // 循环判断与出栈
                        stk.pop();
                        i++;
                    }
                }
                return stk.empty();
            }
        };
    };
};

int main()
{
    Solution *s = new Solution();
    vector<int> v1 = {0, 2, 1};
    vector<int> v2 = {0, 1, 2};
    bool ret = s->validateStackSequences(v1, v2);

    return 0;
}