#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) // head为单节点链表也直接进行返回
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next; // 断开前记录右侧链表头
        slow->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }

private:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

int main()
{
    return 0;
}