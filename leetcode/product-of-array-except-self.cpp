#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0)
            return result;
        result.push_back(1);
        int P = 1;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            P *= nums[i];
            result.push_back(P);
        }
        P = 1;
        for (int i = nums.size() - 1; i >= 1; i--)
        {
           P *= nums[i];
           result[i-1] *= P;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int a[] = {1, 2, 3, 4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<int> result = solution.productExceptSelf(nums);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
