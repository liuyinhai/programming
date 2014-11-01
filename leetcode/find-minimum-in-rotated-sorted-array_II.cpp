#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int subFindMin(vector<int>& num, int s, int e)
    {
      if (s == e || num[s] < num[e])
        return num[s];
      if (s + 1 == e)
      {
        return num[e];
      }
      int m = (s + e) / 2;
      if (num[m] > num[s])
        return subFindMin(num, m, e);
      else if (num[m] < num[s])
        return subFindMin(num, s, m);
      else
      {
        int r1 = subFindMin(num, s, m);
        int r2 = subFindMin(num, m, e);
        return r1 < r2 ? r1 : r2;
      }
    }
    int findMin(vector<int> &num) {
      int s = 0;
      int e = num.size() - 1;
      return subFindMin(num, s, e); 
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  int a[] = {3, 1, 1};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
  {
    vec.push_back(a[i]);
  }
  cout<<s.findMin(vec)<<endl;
  return 0;
}
