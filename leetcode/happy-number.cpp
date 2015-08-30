#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            int s1 = n, s2 = n;
            bool is_even = false;
            while (true)
            {
                int m = 0;
                while (n)
                {
                    m += (n % 10) * (n % 10);
                    n /= 10;
                }
                cout<<"m: "<<m<<endl;
                n = m;
                s1 = m;
                if (is_even)
                {
                    is_even = false;
                    s2 = m;
                }
                else
                {
                    is_even = true;
                }

                if (m == 1)
                {
                    return true;
                }
                if (s1 == s2)
                {
                    return false;
                }
            }
        }
};

int main()
{
    Solution solution;
    cout<<solution.isHappy(2)<<endl;
    cout<<solution.isHappy(7)<<endl;

    return 0;
}
