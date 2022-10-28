#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;
int n;
char game;
string input;
int ans = 0;
vector<string> waiting;
unordered_map<string, bool> name;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> game;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        waiting.push_back(input);
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (name[waiting[i]] == false)
        {
            name[waiting[i]] = true;
            num++;
        }
        if (game == 'Y')
        {
            if (num == 1)
            {
                ans++;
                num = 0;
            }
        }
        else if (game == 'F')
        {
            if (num == 2)
            {
                ans++;
                num = 0;
            }
        }
        else
        {
            if (num == 3)
            {
                ans++;
                num = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}