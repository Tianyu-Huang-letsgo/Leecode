#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            // 核心点: 输入是非递减数组,有序的
            // 方法:对撞双指针
            int i = 0;
            int j = numbers.size() - 1;
            vector<int> ret;
            while(i != j){
                int sum = numbers[i] + numbers[j];
                if(sum == target){
                    ret.push_back(i + 1);
                    ret.push_back(j + 1);
                    break;
                }
                else if(sum > target){
                    j--;
                }
                else{
                    i++;
                }
            }
            return ret;
        }
};