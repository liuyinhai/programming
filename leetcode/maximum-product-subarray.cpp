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
    int maxProduct(int A[], int n)
    {
         int result = 1 << 31;
         int maxP = 1, minP = 1;
         for (int i = 0; i < n; i++)
         {
              if (A[i] == 0)
              {
                   maxP = 0;
                   minP = 0;
              } else if (A[i] > 0)
              {
                   maxP = maxP * A[i];
                   minP = minP * A[i];
              } else if (A[i] < 0)
              {
                   int tmp = maxP;
                   maxP = minP * A[i];
                   minP = tmp * A[i];
              }
              if (maxP > result)
                   result = maxP;
              if (maxP <= 0)
                   maxP = 1;
              if (minP >= 0)
                   minP = 1;
         }
         return result;
    }
};

int main()
{
    Solution s;
    int A[] = {-4, -3, 0, 0};
    cout<<s.maxProduct(A, 4)<<endl;
    return 0;
}
