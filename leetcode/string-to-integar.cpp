#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        unsigned int n = 0;
        int i = 0;
        int is_sign = 1;
        bool is_start = true;
        while (i < str.size())
        {
            if (is_start && str[i] == ' ')
            {
                i++;
                continue;
            }
            if (is_start && str[i] == '-')
            {
                i++;
                is_sign = -1;
                is_start = false;
                continue;
            }
            if (is_start && str[i] == '+')
            {
                i++;
                is_sign = 1;
                is_start = false;
                continue;
            }
            is_start = false;
            if (str[i] >= '0' && str[i] <= '9')
            {
                int d = int(str[i] - '0');
                if (is_sign == 1 && (n > 214748364 || (n == 214748364 && d > 7)))
                    return 2147483647;
                if (is_sign == -1 && (n > 214748364 || (n == 214748364 && d > 8)))
                    return 2147483648;
                n = n * 10 + d;
                i++;
                continue;
            }
            break;
        }
        return is_sign * n;
    }
};

int main()
{
    Solution s;
    cout<<s.myAtoi("    10522545459")<<endl;
    return 0;
}
