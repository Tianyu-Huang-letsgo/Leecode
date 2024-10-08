#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <queue>

using namespace std;

// LRU缓存
// 哈希表 + 双向链表
struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, DLinkedNode *> cache;    // 哈希表： key->node*
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;       // 当前存储量
    int capacity;   // 容量

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        // 使用伪头部和伪尾部节点
        // 1. 可以快速定位头节点和尾节点
        // 2. 避免判读前驱/后继节点是否为空节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {

          
        if (!cache.count(key))
        {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode *node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode *removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏(经典)
                delete removed;
                --size;
            }
        }
        else
        {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 将node与其前驱、后继节点断开
    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main()
{
    return 0;
}