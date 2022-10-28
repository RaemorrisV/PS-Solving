#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<string> words;
vector<string> temp;
unordered_map<string, int> f;
string input;
int s;
int MAX = -1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> input;
        words.push_back(input);
    }
    temp = words;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < s - 1; i++)
    {
        int st = 0;
        int en = 0;
        while (1)
        {
            if (temp[i][en] == temp[i + 1][en])
            {
                en++;
            }
            else
            {
                MAX = max(MAX, en - st);
                if (MAX == en - st)
                {
                    f[temp[i]] = MAX;
                    f[temp[i + 1]] = MAX;
                }
                break;
            }
        }
    }
    for (int i = 0; i < s; i++)
    {
        if (f[words[i]] == MAX)
        {
            for (int j = i + 1; j < s; j++)
            {
                if (f[words[j]] == MAX && words[i].substr(0, MAX) == words[j].substr(0, MAX))
                {
                    cout << words[i] << '\n';
                    cout << words[j] << '\n';
                    exit(0);
                }
            }
        }
    }
    return 0;
}