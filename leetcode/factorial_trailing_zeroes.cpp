#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int countDigitOne(int n)
        {
            vector<int> digit_vec;
            while (true)
            {
                digit_vec.push_back(n % 10);
                n = n / 10;
                if (n == 0)
                    break;
            }
            reverse(digit_vec.begin(), digit_vec.end());
            int cnt = 0;
            int m = 0;
            for (size_t i = 0; i < digit_vec.size(); i++)
            {
                int c = 1;
                for (size_t j = i + 1; j < digit_vec.size(); j++)
                {
                    c *= 10;
                }

                if (digit_vec[i] != 0 && digit_vec[i] != 1)
                {
                    if (m != 0)
                        c *= (m + 1);
                }
                else
                {
                    if (m != 0)
                        c *= m;
                    else
                        c = 0;
                    if (digit_vec[i] == 1)
                    {
                        int tmp = 0;
                        for (size_t j = i + 1; j < digit_vec.size(); j++)
                        {
                            tmp = tmp * 10 + digit_vec[j];
                        }
                        c = c + (tmp + 1);
                    }
                }

                cnt += c;
                m = m * 10 + digit_vec[i];
            }
            return cnt;
        }
};

int main()
{
    Solution s;
    cout<<s.countDigitOne(13)<<endl;
    return 0;
}
