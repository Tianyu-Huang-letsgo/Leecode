#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {5};
    int ret = s->search(v, 5);
    return 0;
}