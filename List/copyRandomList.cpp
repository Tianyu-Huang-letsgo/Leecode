#include <iostream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    // 深拷贝的节点一一对应，考虑使用哈希表进行匹配对应
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> map;
        for (Node *node = head; node; node = node->next)
        {
            map[node] = new Node(node->val);
        }
        for (Node *node = head; node; node = node->next)
        {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
        }
        return map[head];
    }
};