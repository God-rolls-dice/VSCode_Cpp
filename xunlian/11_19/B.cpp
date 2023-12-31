#include <iostream>
#include <cstring>
using namespace std;

void Compare(string& s1, string s2)
{
    s1[0] = '0';
}

int main()
{
    string s1 = "abc", s2 = "def";
    Compare(s1, s2);
    cout << s1;
}