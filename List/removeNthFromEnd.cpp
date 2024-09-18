#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 19. 删除链表的倒数第N个节点
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
    // 思路：递归到最后一个节点进行计数返回
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int cnt = 0;
        ListNode *node_n = head->next;
        return dfs(head, nullptr, n, cnt);
    }

private:
    // 返回计数
    ListNode *dfs(ListNode *node, ListNode *node_pre, int n, int &cnt)
    {
        if (node == nullptr)
        {
            cnt = 1;
            return nullptr;
        }
        node->next = dfs(node->next, node, n, cnt);
        ListNode *ret = node;
        if (cnt == n)
        {
            ret = node->next;
        }
        ++cnt;
        return ret;
    }
};

int main()
{
    ListNode *node = new ListNode(1);
    Solution *s = new Solution();
    s->removeNthFromEnd(node, 1);
    return 0;
}