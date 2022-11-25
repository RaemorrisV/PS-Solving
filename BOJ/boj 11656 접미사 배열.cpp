#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string input;
string temp = "";
vector<string> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> input;
    for (int i = input.length() - 1; i >= 0; i--)
    {
        temp = input[i] + temp;
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << '\n';
    }
    return 0;
}