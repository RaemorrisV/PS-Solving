#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
int MAX = 0;
bool alphabet[26];
vector<string> words;
int cnt_word()
{
    int rvalue = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < words[i].length(); j++)
        {
            if (alphabet[words[i][j] - 'a'])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        if (cnt == words[i].length())
        {
            rvalue++;
        }
    }
    return rvalue;
}
void dfs(int s, int len)
{
    if (len == k)
    {
        MAX = max(MAX, cnt_word());
        return;
    }
    for (int i = s; i < 26; i++)
    {
        if (alphabet[i] == false)
        {
            alphabet[i] = true;
            dfs(i, len + 1);
            alphabet[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        words.push_back(in);
    }
    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    k -= 5;
    if (k >= 0)
    {
        MAX = max(MAX, cnt_word());
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i])continue;
            alphabet[i] = true;
            dfs(i, 1);
            alphabet[i] = false;
        }
    }
    cout << MAX << '\n';
    return 0;
}