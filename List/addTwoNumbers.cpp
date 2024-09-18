#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 两数相加
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int flag = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *p_h = head;
        // 两节点都不为空
        while (p1 && p2)
        {
            ListNode *node = new ListNode((p1->val + p2->val + flag) % 10);
            flag = (p1->val + p2->val + flag) / 10;
            p_h->next = node;
            p_h = p_h->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            ListNode *node = new ListNode((p1->val + flag) % 10);
            flag = (p1->val + flag) / 10;
            p_h->next = node;
            p1 = p1->next;
            p_h = p_h->next;
        }
        while (p2)
        {
            ListNode *node = new ListNode((p2->val + flag) % 10);
            flag = (p2->val + flag) / 10;
            p_h->next = node;
            p2 = p2->next;
            p_h = p_h->next;
        }
        if (flag)
        {
            ListNode *node = new ListNode(flag);
            p_h->next = node;
        }
        return head->next;
    }
};

int main()
{
    return 0;
}