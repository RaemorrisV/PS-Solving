#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
struct info
{
    string h;
    int strike;
    int ball;
};
vector<info> arr;
bool visited[10];
bool valide(string test) // test = 영수가 생각하는 숫자
{
    int check = 0;
    int st = 0;
    int ba = 0;
    for (int i = 0; i < n; i++)
    {
        st = 0;
        ba = 0;
        for (int j = 0; j < 3; j++)
        {
            if (arr[i].h.find(test[j]) != string::npos) //있다면
            {
                int idx = arr[i].h.find(test[j]);
                if (idx == j)
                {
                    st++;
                }
                else
                {
                    ba++;
                }
            }
        }
        if (st == arr[i].strike && ba == arr[i].ball)check++;
    }
    if (check == n)return true;
    return false;
}
void dfs(string cur)
{
    if (cur.length() == 3)
    {
        if (valide(cur))ans++;
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(cur + to_string(i));
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string in;
        int x;
        int y;
        cin >> in >> x >> y;
        arr.push_back({in, x, y});
    }
    for (int i = 1; i <= 9; i++)
    {
        visited[i] = true;
        dfs(to_string(i));
        visited[i] = false;
    }
    cout << ans << '\n';
    return 0;
}