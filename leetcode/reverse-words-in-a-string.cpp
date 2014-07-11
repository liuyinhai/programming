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
     void reverseWords(string &s) {
         string tmp = s;
         s = "";
         size_t last_pos = 0;
         while (true)
         {
             size_t pos = tmp.find(" ", last_pos);
             if (pos == string::npos)
             {
                 s = tmp.substr(last_pos) + " " + s;
                 break;
             }
             if (pos != last_pos)
             {
                 s = tmp.substr(last_pos, pos - last_pos) + " " + s;
             }
             last_pos = pos + 1;
             if (last_pos >= tmp.size())
             {
                 break;
             }
         }
         return ; 
     }
};

int main()
{
    Solution solution;
    string s =  " the  sky is blue ";
    cout<<s<<endl;
    solution.reverseWords(s);
    cout<<s<<endl;
    return 0;
}
