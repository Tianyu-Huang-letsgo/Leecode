#include <stdio.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    // 思路：
    // 无进位和与异或运算规律相同，进位 和 与运算规律相同
    // 二进制相加的规律，先将无进位部分相加，再将上一部分与进位部分相加
    // 在计算机系统中，数值一律使用补码来表示和存储
    int getSum(int a, int b)
    {
        // 这里将a作为"被加数"，b作为"加数"，对所有进位/非进位都加载基准数上
        while (b != 0)
        {
            int c = (unsigned int)(a & b) << 1; // 进位和。这里unsigned int的作用是为了将a&b的结果左移时移位操作是逻辑位移，在负数进行算术位移可能会产生错误（编译器会自动补充零位）
            a = a ^ b;                          // 异或：非进位相加
            b = c;
        }
        return a;
    }
};

int main()
{
    return 0;
}
