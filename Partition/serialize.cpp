#include <iostream>
#include <string>
#include <deque>
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
    // 序列化与反序列化：可将此题归为**二叉树层序遍历**
    // Serialize a binary tree to a single string.
    std::string serialize(TreeNode *root)
    {
        if (!root)
            return "[]";

        std::deque<TreeNode *> queue;
        queue.push_back(root);
        std::ostringstream out;
        out << '[';

        while (!queue.empty())
        {
            TreeNode *node = queue.front();
            queue.pop_front();

            if (node)
            {
                // 只要node != nullptr，无论左右子节点是否为空都推进队列。也借此将node的值为null或有值推入stream
                out << node->val << ',';
                queue.push_back(node->left);
                queue.push_back(node->right);
            }
            else
            {
                out << "null,";
            }
        }

        std::string res = out.str();
        res.back() = ']'; // Replace the last comma with a closing bracket
        return res;
    }

    // Deserialize your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        if (data == "[]")
            return nullptr;

        std::deque<TreeNode *> queue;
        std::istringstream in(data.substr(1, data.size() - 2)); // Remove brackets去除括号:[]
        std::string val;

        getline(in, val, ',');                    // 将stream转化为string，将root->val赋值给val
        TreeNode *root = new TreeNode(stoi(val)); // 将int转化为string
        queue.push_back(root);

        // 核心： 1. 只放非空节点值进入队列；2. 使用两次getline()，每次从stream中读取两个节点信息，这两个节点一定是que.front()的子节点
        while (!queue.empty())
        {
            TreeNode *node = queue.front();
            queue.pop_front();

            if (getline(in, val, ',') && val != "null")
            {
                TreeNode *leftNode = new TreeNode(stoi(val));
                node->left = leftNode;
                queue.push_back(leftNode);
            }

            if (getline(in, val, ',') && val != "null")
            {
                TreeNode *rightNode = new TreeNode(stoi(val));
                node->right = rightNode;
                queue.push_back(rightNode);
            }
        }

        return root;
    }
};

int main()
{
    // Example usage:
    Codec codec;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    std::string serialized = codec.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    TreeNode *deserializedRoot = codec.deserialize(serialized);
    std::string serializedAgain = codec.serialize(deserializedRoot);
    std::cout << "Reserialized tree: " << serializedAgain << std::endl;

    return 0;
}
