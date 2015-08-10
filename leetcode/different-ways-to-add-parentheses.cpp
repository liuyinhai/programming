#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    void cal(stack<int>& s, stack<char>& o, size_t i, const vector<int>& num_vec, const vector<char>& op_vec, vector<int>& result) 
    {
        if (s.empty()) 
        {
            if (i >= num_vec.size())
            {
                return;
            }
            s.push(num_vec[i]);
        } 
        if (s.size() == 1 && i + 1 >= num_vec.size())
        {
            result.push_back(s.top());
            return ;
        }

        if (s.size() >= 2)
        {
            int n2 = s.top();
            s.pop();
            int n1 = s.top();
            s.pop();
            char c = o.top();
            o.pop();
            if (c == '+')
                s.push(n1 + n2);
            else if (c == '-')
                s.push(n1 - n2);
            else if (c == '*')
                s.push(n1 * n2);
            cal(s, o, i, num_vec, op_vec, result);
            s.pop();
            s.push(n1);
            s.push(n2);
            o.push(c);
        }
        if (i + 1 < num_vec.size())
        {
            s.push(num_vec[i+1]);
            o.push(op_vec[i]);
            cal(s, o, i+1, num_vec, op_vec, result);
            o.pop();
            s.pop();
        }
        return ;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> num_vec;
        vector<char> op_vec;
        int num = 0;
        bool last_num = true;
        for (size_t i = 0; i < input.size(); i++)
        {
            char c = input[i];
            if (c == '-' || c == '+' || c == '*')
            {
                if (last_num)
                {
                    num_vec.push_back(num);
                    num = 0;
                }
                op_vec.push_back(c);
                last_num = false;
                continue;
            }
            last_num = true;
            num = num * 10 + int(c - '0');
        }
        if (last_num)
            num_vec.push_back(num);
        vector<int> result;
        stack<int> s;
        stack<char> o;
        cal(s, o, 0, num_vec, op_vec, result);
        return result;
    }
};

int main()
{
    Solution solution;
    string input = "2*3-4*5";
    vector<int> result = solution.diffWaysToCompute(input);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" " <<endl;
    }
    cout<<endl;
    return 0;
}
