#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target, int a, int b, int c, int d)
    {
       //cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
       if (a > c || b > d)
           return false;
       int i = (a + c) / 2; 
       int j = (b + d) / 2;
       //cout<<i<<"\t"<<j<<endl;
       if (matrix[i][j] == target)
           return true;
       if (a == c && b == d)
           return false;
       if ((i + 1 <= c && j + 1 <= d) && (searchMatrix(matrix, target, a, j + 1, i + 1, d) || searchMatrix(matrix, target, i + 1, b, c, j + 1)))
           return true;
       if (matrix[i][j] > target)
       {
           if (searchMatrix(matrix, target, a, j, i - 1, j) || searchMatrix(matrix, target, i, b, i, j - 1))
               return true;
           return searchMatrix(matrix, target, a, b, i - 1 , j - 1);
       }
       else
       {
           if (searchMatrix(matrix, target, i, j + 1, i, d) || searchMatrix(matrix, target, i + 1, j, c, j))
               return true;
           return searchMatrix(matrix, target, i + 1, j + 1, c, d);

       }
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        return searchMatrix(matrix, target, 0, 0, m - 1, n - 1);
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > m;
    int a[] = {1, 4, 7, 11, 15, 2, 5, 8, 12, 19, 3, 6, 9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};
    for (size_t i = 0; i < 5; i++)
    {
        vector<int> v;
        for (size_t j = 0; j < 5; j++)
            v.push_back(a[i * 5 + j]);
        m.push_back(v);
    }
    cout<<solution.searchMatrix(m, 9)<<endl;
    cout<<solution.searchMatrix(m, 20)<<endl;
    return 0;
}
