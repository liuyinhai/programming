#include <cstdlib> 
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
// #include <unordered_map>
// #include <unordered_set>

using namespace std;

class Solution {
public:
    int minCut(string s) {
         int len = s.size();
         if (len == 0) return 0;
         vector<vector<int> > p;
         p.resize(len, vector<int>());
         for (int i = 0; i < len; i++)
         {
              int j = 0;
              while (true)
              {
                   int k1 = i - j;
                   int k2 = i + j;
                   if (k1 < 0 || k2 >= len || s[k1] != s[k2]) break;
                   p[k2].push_back(k1);
                   j++;
              }
              j = 0;
              while (true)
              {
                   int k1 = i - j;
                   int k2 = i + j + 1;
                   if (k1 < 0 || k2 >= len || s[k1] != s[k2]) break;
                   p[k2].push_back(k1);
                   j++;
              }
         }
         
         // for (int i = 0; i < p.size(); i++)
         // {
         //      cout<<i<<":\t";
         //      for (int j = 0; j < p[i].size(); j++)
         //      {
         //           cout<<p[i][j]<<" ";
         //      }
         //      cout<<endl;
         // }
         vector<int> result_vec;
         result_vec.resize(len, len-1);
         for (int i = 0; i < len; i++)
         {
              const vector<int>& sv = p[i];
              for (int j = 0; j < sv.size(); j++)
              {
                   if (sv[j] == 0)
                   {
                       result_vec[i] = 0;
                       continue;
                   }
                   if (result_vec[sv[j]-1] + 1 < result_vec[i])
                       result_vec[i] = result_vec[sv[j]-1] + 1;
              }
         }
         int result = result_vec[len-1];
         return result;
    }
};

int main()
{
    Solution s;
    string str = "ababababababababababababcbabababababababababababa";
    // string str = "abbac";    
    cout<<s.minCut(str)<<endl;
    return 0;
}
