#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [=](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ret.back()[1])
            {
                if (intervals[i][1] >= ret.back()[1])
                    ret.back()[1] = intervals[i][1];
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution *s = new Solution();
    vector<vector<int>> ret;
    ret = s->merge(v);
    return 0;
}