#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> row;
        row.assign(n + 1, 0);
        vector<vector<int> > value;
        value.assign(m + 1, row);
        int min_num = 0;
        for (int j = 1; j <= n; j++)
        {
            min_num += grid[0][j-1];
            value[1][j] = min_num;
        }
        min_num = 0;
        for (int i = 1; i <= m; i++)
        {
            min_num += grid[i-1][0];
            value[i][1] = min_num;
        }
        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                int v = value[i-1][j];
                if (v > value[i][j-1]) v = value[i][j-1];
                value[i][j] = v + grid[i-1][j-1];
            }
        }
        return value[m][n];
    }
};

int main()
{
    vector<vector<int> > grid;
    vector<int> row;
    row.push_back(1);
    row.push_back(2);
    grid.push_back(row);
    row.clear();
    row.push_back(1);
    row.push_back(1);
    grid.push_back(row);
    Solution s;
    int v = s.minPathSum(grid);
    cout<<v<<endl;
    return 0;
}
