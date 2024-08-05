#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        vec_.push_back(num);
    }

    double findMedian()
    {
        vector<int> tmp_vec = vec_;
        sort(tmp_vec.begin(), tmp_vec.end());
        if (tmp_vec.size() % 2 != 0)
        {
            int index = tmp_vec.size() / 2;
            return tmp_vec.at(index);
        }
        else
        {
            int ind1 = tmp_vec.size() / 2 - 1;
            int ind2 = tmp_vec.size() / 2;
            double num1 = double(tmp_vec.at(ind1));
            double num2 = double(tmp_vec.at(ind2));
            return (num1 + num2) / 2;
        }
    }

private:
    vector<int> vec_;
};

int main()
{
    MedianFinder *med = new MedianFinder();
    med->addNum(1);
    med->addNum(2);
    double media = med->findMedian();
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */