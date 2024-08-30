#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// !!在priority_queue比较函数中，实际上定义了"优先级较低"的条件，函数返回True，则第一个参数的优先级较低
class CmpSecond
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second; // !!这里需要注意好
    }
};

// 前K个高频元素
// 思路：使用哈希表记录nums中元素出现的个数，在通过优先队列进行逐个返回
// 难点在于伪函数CmpSecond()的书写与理解
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash; // 元素及对应个数
        for (auto num : nums)
        {
            hash[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpSecond> q;
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            q.push(make_pair(it->first, it->second));
        }
        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3};
    Solution *s = new Solution();
    s->topKFrequent(v, 2);
    return 0;
}