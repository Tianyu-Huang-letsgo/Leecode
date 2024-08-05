#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 思路：寻找规律，两端字符串进行拼接，能找到goal说明是反转字符串
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && ((s + s).find(goal) != -1);
    }
};

int main()
{
    Solution *s = new Solution();
    bool ret = s->rotateString("bbbacddceeb", "ceebbbbacdd");
    return 0;
}