#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
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
            slow = slow->next;
            fast = fast->next->next;
            if(fast == nullptr){
                return nullptr;
            }
            if(slow == fast){
                break;
            }
        }
        fast = head;
        while (fast!= slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{
    Solution *s = new Solution();

    return 0;
}