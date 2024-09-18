#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 环形链表Ⅱ
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 寻找距离尾部k个节点,寻找环入口,寻找公共尾部入口一般都使用双指针法
        // 双指针法:有头尾指针、快慢指针。
        // 链表有一个很大的约束的就是不知道走的距离
        ListNode *slow = head;
        ListNode *fast = head;
        while (true)
        {
            // 如果fast指向的下一个节点为空节点也直接返回：目的是为了使双步走能正常运行
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        fast = head;
        while (fast != slow) // 核心：c+圈的整数倍才等于a
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{
    return 0;
}