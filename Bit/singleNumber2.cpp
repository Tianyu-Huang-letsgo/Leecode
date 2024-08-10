#include <vector>

using namespace std;

class Solution
{
public:
    // 使用有限状态自动机
    // 整数的32位中每一位存在三个状态，使用ones,two两位进行表示
    // 对于整数的所有位，计算方式都是一样的
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (int num : nums)
        {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones; // 最后遍历完，two状态必然为0，所有信息都存在one中
    }
};

int main()
{

    return 0;
}