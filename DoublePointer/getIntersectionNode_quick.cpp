#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    // 双指针思路：
    // 1. 使用双指针分别对两条链进行遍历，遍历到终点则指向另一个链
    // 2. 如果有交点，一定会在第二次遍历的交点时候退出循环；如果没有交点，会在第二次遍历的时候终点处退出循环；
    // 3. 核心是抓住链A+链B路径和相同的特性
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa != pb)
        {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};

int main()
{
    Solution *s = new Solution();

    return 0;
}
