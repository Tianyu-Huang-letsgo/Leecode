#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

// 前缀树：典型的多叉树（26叉树）模型
// 又名字典树、前缀树、单词查找数
class Trie
{
public:
    Trie()
    {
        // **指针在大多数现代计算机和操作系统上的NULL值全是0**
        memset(next, 0, sizeof(next));
        isEnd = false; // 节点是一个串的结束
    }

    void insert(string word)
    {
        Trie *node = this;
        for (auto ch : word)
        {
            if (node->next[ch - 'a'] == NULL)
            {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (auto ch : word)
        {
            if (node->next[ch - 'a'] == NULL)
            {
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return node->isEnd; // 注意：这里要return node->isEnd.不是终止不能作为单词
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (auto ch : prefix)
        {
            if (node->next[ch - 'a'] == NULL)
            {
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return true;
    }

private:
    Trie *next[26];
    bool isEnd;
};

int main()
{

    return 0;
}