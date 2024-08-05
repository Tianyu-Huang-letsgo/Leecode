#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){} 
    ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                     
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int cnt = 0;
        unordered_map<int, ListNode*> hash;
        for (ListNode *h = head; h; h = h->next)
        {
            hash.insert(make_pair(cnt, h));
            cnt++;
        }
        if(cnt%2 == 0){
            return hash[cnt/2];
        }
        else{
            return hash[cnt/2+1];
        }
    }
};

int main()
{
    Solution *s = new Solution();
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    bool ret = s->middleNode(head);
    cout << ret;
    return 0;
}