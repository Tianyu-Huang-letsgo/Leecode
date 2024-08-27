#include <iostream>
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
    // 思路：创建两条链表，分别指向小于x的节点与指向大于等于x的节点
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *node1 = new ListNode();
        ListNode *node2 = new ListNode();
        ListNode *node = head;
        ListNode *node11 = node1;
        ListNode *node22 = node2;
        while (node != nullptr)
        {
            if (node->val < x)
            {
                node11->next = node;
                node11 = node11->next;
            }
            else
            {
                node22->next = node;
                node22 = node22->next;
            }
            node = node->next;
        }
        node22->next = nullptr; // 难点：需要重置大节点的尾端指向，否则有可能指向 小端节点
        node11->next = node2->next;
        return node1->next;
    }
};

int main()
{
}