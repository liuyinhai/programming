#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s.size() == 0)  return 0;
        int symbol_num = 7;
        char symbol[] = "MDCLXVI";
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        int i, j;
        for (i = 0; i < symbol_num; i++)
        {
             char ch = symbol[i];
             for (j = 0; j < s.size(); j++)
             {
                  if (s[j] == ch) break;
             }
             if (j != s.size()) break;
        }
        int r1 = romanToInt(s.substr(0, j));
        int r2 = romanToInt(s.substr(j+1));
        int result = value[i] - r1 + r2;
        return result;
    }
    
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (num <= 0) return ""; 

        int symbol_num = 7;
        char symbol[] = "MDCLXVI";
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        int i;
        for (i = 0; i < symbol_num; i++)
        {
            if (num >= value[i]) break;
        }
        int j = i + i % 2;
        string result;
        if (i == 0)
        {
            result.assign(1, symbol[0]);
            result += intToRoman(num - value[0]);
        } else if (value[i-1] - num <= value[j])
        {
            result.append(1, symbol[j]);
            result.append(1, symbol[i-1]);
            result = result + intToRoman(num - value[i-1] + value[j]);
        } else
        {
            result.assign(1, symbol[i]);
            result = result + intToRoman(num - value[i]);
        }
        return result;
    }    
};

int main()
{
    Solution s;
    int array[] = {6, 40, 1904};
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        string str = s.intToRoman(array[i]);
        cout<<array[i]<<"\t"<<str<<endl;
    }
    return 0;
}
