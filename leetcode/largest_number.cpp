#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        static string Int2String(int num)
        {
            string s = "";
            while (true)
            {
                s = s + string(1, '0' + num % 10);
                num = num / 10; 
                if (num == 0)
                    break;
            }
            reverse(s.begin(), s.end());
            return s;
        }
        static int cmp(int a, int b)
        {
            string sa = Int2String(a);
            string sb = Int2String(b);
            return sa + sb > sb + sa;
        }

        string largestNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end(), cmp); 
            string r = "";
            for (size_t i = 0; i < nums.size(); i++)
            {
                r = r + Int2String(nums[i]);
            }
            return r;
        }
};

int main()
{
    int A[] = {3, 30, 34, 5, 9};
    vector<int> nums(A, A + 5);
    Solution s;
    cout<<s.largestNumber(nums)<<endl;
    return 0;
}
