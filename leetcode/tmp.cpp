#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s = "liu";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    cout<<string(1, '0' + 1)<<endl;
    vector<int> A(10, 100);
    for (auto a : A)
        cout<<a<<endl;
    return 0;
}
