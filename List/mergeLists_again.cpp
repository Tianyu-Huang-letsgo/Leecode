#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

// 23. 合并K个升序链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 方法一：使用二分法进行合并
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode head;
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *tail = &head;
        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                tail->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                tail->next = ptr2;
                ptr2 = ptr2->next;
            }
            tail = tail->next;
        }
        tail->next = ptr1 ? ptr1 : ptr2;
        return head.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
        {
            return lists[l];
        }
        if (l > r)
        {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
};

// 方法二：优先队列
class Solution
{
public:
    struct status
    {
        status(ListNode *node_, int val_) : node(node_), val(val_) {};
        ListNode *node;
        int val;
        bool operator<(const status &cmp) const // 注意点1. 重载的<符号只能比较相同类型的数据结构，也就是status只能与status相比，；2. 这里只有在参数列表加上const与代码块前加上const，程序才不会报错。
        {
            return val > cmp.val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode head;
        ListNode *tail = &head;
        priority_queue<status> q;
        for (auto l : lists)
        {
            if (l)
            {
                q.push(status(l, l->val)); // 核心：将每一个链表的首节点存进优先队列中
            }
        }
        while (!q.empty())
        {
            ListNode *node = q.top().node;
            q.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next != nullptr)
            {
                q.push({node->next, node->next->val});
            }
        }
        return head.next;
    }
};

int main()
{
    return 0;
}