
#include <iostream>
#include <vector>
#include <algorithm> // for sort

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;

        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (size_t k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0)
                break; // If the current number is greater than 0, break (since nums[j] > nums[i] > nums[k])

            if (k > 0 && nums[k] == nums[k - 1])
                continue; // Skip the same `nums[k]`

            size_t i = k + 1, j = nums.size() - 1;

            // Step 3: Use two pointers to find the other two numbers
            while (i < j)
            {
                // 在这里已经完成运算了
                int s = nums[k] + nums[i] + nums[j];

                if (s < 0)
                {
                    ++i;
                    while (i < j && nums[i] == nums[i - 1])
                        ++i; // Skip the same `nums[i]`
                }
                else if (s > 0)
                {
                    --j;
                    while (i < j && nums[j] == nums[j + 1])
                        --j; // Skip the same `nums[j]`
                }
                else
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    ++i;
                    --j;
                    while (i < j && nums[i] == nums[i - 1])
                        ++i; // Skip the same `nums[i]`
                    while (i < j && nums[j] == nums[j + 1])
                        --j; // Skip the same `nums[j]`
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = solution.threeSum(nums);

    for (const auto &triplet : res)
    {
        std::cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i)
        {
            std::cout << triplet[i];
            if (i < triplet.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}