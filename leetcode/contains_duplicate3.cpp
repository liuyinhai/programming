#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            unordered_map<int, int> M;
            for (size_t i = 0; i < nums.size(); i++)
            {
                unordered_map<int, int>::iterator it = M.find(nums[i]);
                if (it != M.end() && i - it->second <= k)
                    return true;
                M[nums[i]] = i;
            }
            return false;
        }
};

int main()
{
    Solution s;
    int A[] = {3, 1, 2, 4, 1, 5, 16};
    vector<int> nums(A, A + 7);
    cout<<s.containsNearbyAlmostDuplicate(nums, 1, 3)<<endl;
    return 0;
}
