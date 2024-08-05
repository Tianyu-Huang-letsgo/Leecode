#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        // int index = 0;
        int hash[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (hash[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution *s = new Solution();
    int index = s->firstUniqChar("leecode");
    cout << index;
}