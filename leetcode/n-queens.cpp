#include <iostream>

using namespace std;

class Solution {
public:
    bool FillBoard(
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<char> > board = vector<vector<char> >();
        
    }
};

int main()
{
    Solution s;
    vector<vector<string> > solution_vec = s.solveNQueens(4);
    cout<<solution_vec.size()<<endl;
    for (int i = 0; i < solution_vec.size(); i++)
    {
        cout<<endl;
        const vector<string>& solution = solution_vec[i];
        for (int j = 0; j < solution.size(); j++)
        {
            cout<<solution[j]<<endl;
        }
    }
    
    return 0;
}
