#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string words, want;
int ans = 0;
int main()
{
    getline(cin, words);
    getline(cin, want);
    int idx = words.find(want);
    while (1)
    {
        if (idx == string::npos)break;
        ans++;
        idx=words.find(want,idx+want.length());
    }
    cout << ans << '\n';
    return 0;
}