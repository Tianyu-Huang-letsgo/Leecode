#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 24. 两两交换链表中的节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 思路： 做dfs进行深度遍历交换，计数双数时，进行操作
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        return dfs(head, nullptr, 1);
    }

private:
    ListNode *dfs(ListNode *node, ListNode *node_pre, int cnt)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (cnt % 2 == 0)
        {
            ListNode *node_nex = node->next;
            node->next = node_pre;
            node_pre->next = dfs(node_nex, node, cnt + 1);
        }
        else
        {
            ListNode *tmp = node;
            node = dfs(node->next, node, cnt + 1); // 单数点也要等一个返回值，而且需要做末尾数字判断
            node = node ? node : tmp;
        }

        return node;
    }
};

int main()
{
    return 0;
}