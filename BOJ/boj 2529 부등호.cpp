#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int k;
vector<char> arr;
char input;
bool visited[10];
vector<string> ans;
void dfs(int s, int cnt, string temp)
{
    visited[s] = true;
    temp += to_string(s);
    if (cnt == k)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (arr[cnt] == '<')
        {
            if (visited[i] == false && s < i)
            {
                dfs(i, cnt + 1, temp);
                visited[i] = false;
            }
        }
        else
        {
            if (visited[i] == false && s > i)
            {
                dfs(i, cnt + 1, temp);
                visited[i] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    for (int i = 0; i < 10; i++)
    {
        dfs(i, 0, "");
        visited[i] = false;
    }
    cout << ans[ans.size() - 1] << '\n' << ans[0] << '\n';
    return 0;
}