#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
// 数据流的中位数

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // 约定小顶堆先放一个数值（A.size() >= B.size()）
        // 1. 需要保持|A.size() - B.size()| <=1
        // 2. 需要保证小顶堆的顶部大于等于大顶堆的顶部
        // 方法：要向A存，就要拿出B最大的；向B存，就要拿出A最小的
        // 优先队列有一个很重要的性质：存放、取出元素会自动将最大/最小值放在堆顶位置，因此不用进行元素比较
        if (A.size() == B.size()) // 大半数值约定更多
        {
            B.push(num);
            A.push(B.top()); // 永远将我的最大值给你
            B.pop();
        }
        else
        {
            A.push(num);
            B.push(A.top()); // 永远将我的最小值给你
            A.pop();
        }
    }

    double findMedian()
    {
        double ret;
        if (A.size() == B.size())
        {
            ret = double(A.top() + B.top()) / 2;
        }
        else
        {
            ret = A.top();
        }

        return ret;
    }

private:
    priority_queue<int, vector<int>, greater<int>> A; // 小顶堆存大半数值
    priority_queue<int, vector<int>, less<int>> B;    // 大顶堆存小半数值
};

int main()
{
    return 0;
}