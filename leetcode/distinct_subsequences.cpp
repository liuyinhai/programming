#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int numDistinct(string s, string t) {
            int n = t.size();
            if (n == 0)
                return 0;
            vector<int> A(n, 0);
            for (size_t i = 0; i < s.size(); i++)
            {
                for (int j = n - 1;  j >= 0; j--)
                {
                    if (t[j] == s[i])
                    {
                        if (j == 0)
                        {
                            A[j] += 1;
                        }
                        else
                        {
                            A[j] += A[j-1];
                        }

                    }
                }
            }
            return A[n-1];
        }
};

int main()
{
    Solution s;
    cout<<s.numDistinct("rabbbit", "rabbit")<<endl;
    return 0;
}
