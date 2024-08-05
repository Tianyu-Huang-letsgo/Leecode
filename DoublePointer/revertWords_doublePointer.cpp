#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> wordsVector;
        int i, j;
        i = s.size() - 1;
        j = i;

        while (i >= 0)
        {
            while (i >= 0 && s[i] != ' ')
                i--;

            if (i != j)
                wordsVector.push_back(s.substr(i + 1, (j - i))); // 由于i已经移动到字符之前，所以是i+1

            // 除去空格
            while (i >= 0 && s[i] == ' ')
            {
                i--;
                j = i; // j与i进行同步
            }
        }

        string result;
        for (int n = 0; n < wordsVector.size(); ++n)
        {
            result += wordsVector[n];
            if (n != wordsVector.size() - 1)
                result += ' ';
        }

        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    string ret = s->reverseWords("   the sky is blue   ");
    cout << ret;
    return 0;
}