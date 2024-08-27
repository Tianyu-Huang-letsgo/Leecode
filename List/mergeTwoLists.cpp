#include <stdio.h>
#include <iostream>

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
    // l1,l2均按照非递减顺序排序
    // 核心思路：
    // 1. 逐元素比较，当前队列当前元素更小，换下一个元素跟你比较
    // 2. 因为有两个链表，采用双指针思路，每个指针遍历一个链表
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 当拿出来比较的元素越界，只能返回另一个元素
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    return 0;
}