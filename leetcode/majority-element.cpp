#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == num)
                count++;
            else 
            {
                if (count > 0)
                    count--;
                else
                    num = nums[i];
            }
        }
        return num;
    }
};

int main()
{
    Solution solution;
    int a[] = {5, 1, 2, 1, 1, 4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout<<solution.majorityElement(nums);
    return 0;
}
