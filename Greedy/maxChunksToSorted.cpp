#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // 思路：每一块的最大值记为head，目标就是要做到每一块的head>=上一块的head。
    int maxChunksToSorted(vector<int> &arr)
    {
        vector<int> stack;
        for (int num : arr)
        {
            if (!stack.empty() && num < stack.back())       // stack.back()存着最后一块的最大值
            {
                int head = stack.back();
                stack.pop_back();
                while (!stack.empty() && num < stack.back())
                {
                    stack.pop_back();
                }
                stack.push_back(head);
            }
            else
            {
                stack.push_back(num);
            }
        }
        return stack.size();
    }
};

int main()
{

    return 0;
}