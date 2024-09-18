#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 148. 排序链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 思路：归并排序
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head; // 终止条件。

        // 使用快慢指针找到中点。慢指针：1，2，3...；快指针：2，4，6...
        // 这里我们要找的是第一段的尾节点（核心是要进行断开操作）而不是第二段的头节点，所以fast从第二个节点开始
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) // 快指针需要判断其next才不会越界
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 切分链表
        ListNode *mid = slow->next; // mid作为右端的头节点（切断之前先记录）
        slow->next = nullptr;

        // 递归排序左右两部分
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        // 合并排序后的链表
        return merge(left, right);
    }

private:
    // 合并两个排序链表的辅助函数
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2; // l1最多比l2多一个节点
        return dummy.next;
    }
};

int main()
{
    return 0;
}