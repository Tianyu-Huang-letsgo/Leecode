#include <vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

// LRU缓存
// 哈希表 + 双向链表
// 链表最大特点：增加节点/删除节点都是O(1)复杂度的
struct DLinkedNode
{
    DLinkedNode *prev;
    DLinkedNode *next;
    int key;
    int val;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {};
    DLinkedNode(int key_, int val_) : key(key_), val(val_), prev(nullptr), next(nullptr) {};
};

class LRUCache
{
private:
    DLinkedNode *head;
    DLinkedNode *tail;
    int size_;
    int capacity_;
    unordered_map<int, DLinkedNode *> hash_; // 使用key作为哈希表键， 节点指针作为哈希表值；因为节点可能包含很多信息

public:
    LRUCache(int cap) : capacity_(cap), size_(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    };

    int get(int key)
    {
        if (hash_.count(key))
        {
            DLinkedNode *node = hash_[key];
            moveToHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (hash_.count(key)) // 原有，更新哈希表
        {
            DLinkedNode *node = hash_[key];
            node->val = value;
            moveToHead(node);
        }
        else // 源链表不存在节点
        {
            if (size_ >= capacity_) // 缓存满了就要将最尾节点去掉
            {
                DLinkedNode *tail = removeTail();
                hash_.erase(tail->key);
                delete tail;
                size_--;
            }
            DLinkedNode *newNode = new DLinkedNode(key, value);
            addToHead(newNode);
            size_++;
            hash_.insert(make_pair(key, newNode));
        }
    }

    // 原队列中存在节点
    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

    // 新增节点
    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
};

int main()
{
    return 0;
}