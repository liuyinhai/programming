#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        string convert(string s, int numRows) {
            vector<vector<char> > char_vec_vec;
            for (size_t i = 0; i < numRows; i++)
            {
                char_vec_vec.push_back(vector<char>());
            }
            int inx = 0;
            while (true)
            {
                for (size_t j = 0; j < numRows; j++)
                {
                    if (inx >= s.size())
                        break;
                    char_vec_vec[j].push_back(s[inx++]);
                }

                for (int j = numRows - 2; j >= 1; j--)
                {
                    if (inx >= s.size())
                        break;
                    char_vec_vec[j].push_back(s[inx++]);
                }
                if (inx >= s.size())
                    break;
            }
            string result;
            for (size_t i = 0; i < numRows; i++)
            {
                for (size_t j = 0; j < char_vec_vec[i].size(); j++)
                {
                    result += string(1, char_vec_vec[i][j]);
                }
            }
            return result;
        }
};

int main()
{
    Solution s;
    cout<<s.convert("1234567890", 1)<<endl;
    return 0;
}
