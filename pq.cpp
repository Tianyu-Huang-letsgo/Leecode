#include <iostream>
#include <queue>
#include <string>

struct Person
{
    string name;
    int age;
};

class ComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        // 优先比较年龄，年轻的人在前面（最小堆）
        return p1.age > p2.age;
    }
};

int main()
{
    std::priority_queue<Person, std::vector<Person>, ComparePerson> pq;

    // 添加几个 Person 实例
    pq.push({"Alice", 30});
    pq.push({"Bob", 25});
    pq.push({"Carol", 35});

    // 输出并移除元素
    while (!pq.empty())
    {
        Person p = pq.top();
        std::cout << p.name << " (" << p.age << " years old)" << std::endl;
        pq.pop();
    }

    return 0;
}
