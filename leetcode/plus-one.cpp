#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int val = digits[i] + carry;
            carry = 0;
            if (val == 10)
            {
                val = 0;
                carry = 1;
            }
            result.insert(result.begin(), val);
        }
        if (carry == 1) result.insert(result.begin(), 1);
        return result;
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
    vector<int> vec, result;
    vec.push_back(0);
    Solution s;
    result = s.plusOne(vec);
    PrintVector(result);
    return 0;
}
