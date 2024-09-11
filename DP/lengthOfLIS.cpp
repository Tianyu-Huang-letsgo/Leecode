#include <vector>
#include <algorithm>

using namespace std;
// 最长递增子序列
// 要求：严格递增
class Solution
{
public:
    // K神题解：dp[i]表示以nums[i]为结尾的最场子序列长度，注意，是一定包括num[i]的子字符串序列！！这样才能将问题具体化,一定接上你下一个才能跟你进行比较
    // 状态转移：当前索引i可以从之前的哪个索引转移过来？答案：1.j<i, 2. nums[j] < nums[i]
    int lengthOfLIS(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) // j在i之前且nums[i] 能跟在nums[j]后面
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

// 单调栈不可解题：遇到一个极小值就会将之前序列断掉
// [0,1,0,3,2,3]
class Solution2
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        vector<int> st;
        st.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            while (!st.empty() && nums[i] <= st.back())
            {
                st.pop_back();
            }
            st.push_back(nums[i]);
            len = max(len, int(st.size()));
        }
        return len;
    }
};

int main()
{
    Solution *s = new Solution();
    std::vector<int> v = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int ret = s->lengthOfLIS(v);
    return 0;
}
