#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        if (n <= 0) return result;
        vector<int> vec1, vec2;
        for (int i = 1; i <= n; i++) vec1.push_back(i);
        simulate(vec1, vec2, "", result);
        return result;
    }
    void simulate(vector<int> vec1, vector<int> vec2, string str, vector<string>& result)
    {
        if (vec1.size() == 0 && vec2.size() == 0)
        {
            result.push_back(str);
            return ;
        }
        if (vec1.size() != 0)
        {
            int val = vec1[0];
            vec1.erase(vec1.begin());
            vec2.push_back(val);
            simulate(vec1, vec2, str + "(", result);
            vec2.pop_back();
            vec1.insert(vec1.begin(), val);
        }
        
        if (vec2.size() != 0)
        {
            int val = vec2[vec2.size()-1];
            vec2.pop_back();
            simulate(vec1, vec2, str + ")", result);
            vec2.push_back(val);
        }
    }
};

void PrintVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<"\t";
    cout<<endl;
}

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> result = s.generateParenthesis(n);
    PrintVector(result);
    return 0;
}
