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
    int findMin(vector<int> &num) {
      int s = 0;
      int e = num.size() - 1;
      while (s <= e)
      {
        if (s == e)
          return num[s];
        if (num[s] < num[e])
          return num[s];
        if (s + 1 == e)
        {
          if (num[s] > num[e])
            return num[e];
          else
            return num[s];
        }
        int m = (s + e) / 2;
        if (num[m] > num[s])
          s = m;
        else if (num[m] < num[s])
          e = m;
      }
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  int a[] = {1, 2, 3};
  vector<int> vec;
  for (size_t i = 0; i < 3; i++)
  {
    vec.push_back(a[i]);
  }
  cout<<s.findMin(vec)<<endl;
  return 0;
}
