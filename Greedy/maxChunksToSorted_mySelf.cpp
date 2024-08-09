#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        stack<int> headers; // 存储每一个块的最大值
        for (auto num : arr)
        {
            if (!headers.empty() && num < headers.top())
            {
                int header = headers.top();
                headers.pop();
                while (!headers.empty() && headers.top() > num)     // 不断遍历，融合；如果值比header小，只能不断相融
                {
                    headers.pop();
                }
                headers.push(header);
            }
            else
            {
                headers.push(num);
            }
        }
        return headers.size();
    }
};

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    Solution *s = new Solution();
    int ret = s->maxChunksToSorted(v);
    return 0;
}
