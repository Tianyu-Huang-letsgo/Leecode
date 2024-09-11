#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;
        vector<int> layer; // 记录上一层的状态
        layer.push_back(1);
        ret.push_back(layer);
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> tmp(i, 1);
            for (int j = 0; j < i; j++)
            {
                if (j == 0 || j == i - 1)
                {
                    tmp[j] = 1;
                }
                else
                {
                    tmp[j] = layer[j - 1] + layer[j];
                }
            }
            ret.push_back(tmp);
            layer = tmp;
        }
        return ret;
    }
};

int main()
{
    return 0;
}