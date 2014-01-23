#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int max_len = 0;
        int num[256];
        memset(num, 0, sizeof(num));
        int b = 0, i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (num[int(s[i])] == 1)
            {
                if (i - b > max_len)
                    max_len = i - b;
                // cout<<i<<"\t"<<s.substr(b, i - b)<<"\t"<<max_len<<endl;
                int j; 
                for (j = b; j < i; j++)
                {
                    num[int(s[j])] = 0;
                    if (s[j] == s[i]) break;
                }
                b = (j+1) < i ? (j+1) : i;
            }
            num[int(s[i])] = 1;
        }
        if (i - b > max_len)
            max_len = i - b;
        return max_len;
    }
};

void PrintVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<"\t";
    cout<<endl;
}

int main()
{
    string str;
    Solution s;
    str = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";
    str = "";
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
