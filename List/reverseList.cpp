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
    // 节点的范围是[0, 5000]
    // 1. 迭代
    // 2. 使用双指针，一个指向当前节点，一个指向上一个节点，一个临时指针暂存下一个节点。
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = pev;
            pev = cur;
            cur = next;
        }
        return pev; // pev才是最后一个非空值
    }

    // 递归
    ListNode *reverseList2(ListNode *head)
    {
        return recur(head, nullptr);
    }

private:
    // 递归参数为**当前节点**及其**前驱节点**
    ListNode *recur(ListNode *cur, ListNode *pre)
    {
        if (cur == nullptr)
        {
            return pre;
        }
        ListNode *res = recur(cur->next, cur); // 用于不断递归找到头节点
        cur->next = pre;                       // 当前层核心操作：指针指向反转
        return res;                            // 每一层的res都相同：头节点
    }
};

int main()
{
    return 0;
}
