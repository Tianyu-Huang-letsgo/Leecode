#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 141. 环形链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *pa = head;
        int ret = false;
        while (pa)
        {
            if (pa->val == INT_MIN)
            {
                ret = true;
                break;
            }
            pa->val = INT_MIN;
            pa = pa->next;
        }
        return ret;
    }
};

int main()
{
    return 0;
}