#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 贪心思路: 只有移动短的边才有扩大容量的可能
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int max_quan = 0;
        while (i < j)
        {
            max_quan = max(max_quan, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_quan;
    }
};

int main()
{

    return 0;
}