#include <iostream>

using namespace std;

class Solution {
public:
    char binary_add(char a, char b, bool& carry)
    {
        int n1 = (a == '0' ? 0 : 1);
        int n2 = (b == '0' ? 0 : 1);
        int n3 = n1 + n2;
        if (carry) n3++;
        carry = (n3 >= 2) ? true : false;
        char c = (n3 % 2 == 0 ? '0' : '1');
        return c;
    }
    
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        bool carry = false;
        string c;
        string tmp;
        if (a.size() < b.size())
        {
            
            tmp = a;
            a = b;
            b = tmp;
        } 
        int min_len = b.size();
        for(int i = 0; i < min_len; i++)
        {
            char c1 = a[a.size() - 1 - i];
            char c2 = b[b.size() - 1 - i];
            char c3 = binary_add(c1, c2, carry);
            c.insert(0, 1, c3);
            cout<<"1\t"<<c1<<"\t"<<c2<<"\t"<<c<<endl;
        }
        for (int i = a.size() - min_len - 1; i >= 0; i--)
        {
            char c3 = binary_add(a[i], '0', carry);
            c.insert(0, 1, c3);
            cout<<"2\t"<<c3<<"\t"<<c<<endl;
        }
        if (carry) c.insert(0, 1, '1');
        return c;
    }
};

int main()
{
    Solution solution;
    cout<<solution.addBinary("1010", "1011")<<endl;
    return 0;
}
