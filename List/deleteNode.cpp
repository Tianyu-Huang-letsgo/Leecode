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
    // 题目强调了链表所有节点值唯一，又不能访问头节点，只能使用《替身法》,将自己替换为后继节点。
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    return 0;
}