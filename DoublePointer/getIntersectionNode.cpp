#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// using namespace std;

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
    // 思路：遍历一个链表，记录所有节点地址；遍历另外一个链表，作地址对比，地址能匹配则返回，不能匹配返回NULL
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        std::vector<ListNode *> node_list1;
        for (ListNode *node = headA; node; node = node->next)
        {
            node_list1.push_back(node);
        }
        // 遍历链表B，查找是否有节点在vector中存在
        for (ListNode *node = headB; node; node = node->next)
        {
            auto it = std::find(node_list1.begin(), node_list1.end(), node);
            if (it != node_list1.end())
            {
                return node; // 找到交叉节点
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution *s = new Solution();

    return 0;
}
