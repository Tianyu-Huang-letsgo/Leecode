#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        // 思路：使用双指针从尾部分别从开始遍历，通过字符ASCII码进行计算出字符，叠加
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string ret_str = "";
        bool flag;
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int ret = n1 + n2 + flag;
            flag = ret / 10;
            ret = ret % 10;
            ret_str = char(ret + '0') + ret_str;
            i--;
            j--;
        }
        if (flag)
        {
            ret_str = '1' + ret_str;
        }
        return ret_str;
    }
};

int main()
{

    Solution *s = new Solution();
    std::string ret = s->addStrings("100", "100");
    return 0;
}