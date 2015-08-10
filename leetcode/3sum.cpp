#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int> > result;
            if (nums.size() < 3)
                return result;
            int L = nums.size();
            for (size_t i = 0; i < L - 2; i++)
            {
                if (nums[i] > 0)
                    return result;
                if (nums[i] + nums[L-1] * 2 < 0)
                    continue;
                for (size_t j = i + 1; j < L - 1; j++)
                {
                    int num = 0 - nums[i] - nums[j];
                    if (nums[i] + nums[j] > 0)
                    {
                        break;
                    }
                    if (num < nums[j+1] || num > nums[L-1])
                        continue;

                    int s = j + 1, t = L - 1;
                    bool is_find = false;
                    while (s <= t)
                    {
                        int m = (s + t) / 2;
                        if (nums[m] == num)
                        {
                            is_find = true;
                            break;
                        } else if (nums[m] < num)
                        {
                            s = m + 1;
                        }
                        else
                        {
                            t = m - 1;
                        }
                    }

                    if (is_find)
                    {
                        int R = result.size();
                        if (R > 0 && nums[i] == result[R-1][0] && nums[j] == result[R-1][1])
                            continue;
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(num);
                        result.push_back(tmp);
                    }
                }

            }
            return result;
        }
};

int main()
{
    Solution solution;
    //int a[] =  {-1,0,1,2,-1,-4};
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > result = solution.threeSum(nums);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
            cout<<result[i][j]<<" ";
        cout<<endl;

    }
    return 0;
}
