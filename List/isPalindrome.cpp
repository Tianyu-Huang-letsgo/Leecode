#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>

using namespace std;

// 234. 回文链表
// 难点：单链表，不知长度
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *pa = head;
        while (pa)
        {
            v.push_back(pa->val);
            pa = pa->next;
        }

        for (int i = 0, j = v.size() - 1; i <= j; ++i, --j)
        {
            if (v[i] != v[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    n1->next = n2;
    Solution *s = new Solution();
    bool ret = s->isPalindrome(n1);
    return 0;
}