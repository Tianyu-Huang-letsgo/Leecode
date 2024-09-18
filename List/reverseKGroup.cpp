#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// k个一组反转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 思路：k个一组，不满k个返回头
        ListNode *nod_next = head;
        for (int cnt = 0; cnt < k; ++cnt)
        {
            if (nod_next == nullptr)
            {
                return head;
            }
            nod_next = nod_next->next; // 注意：这里是一个一个计数
        }
        ListNode *cur = head;
        ListNode *pre = reverseKGroup(nod_next, k);
        for (int i = 0; i < k; ++i)
        {
            ListNode *tmp = cur->next; // 断开了一条链子记录断掉的节点
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    Solution *s = new Solution();
    s->reverseKGroup(node1, 2);
    return 0;
}
