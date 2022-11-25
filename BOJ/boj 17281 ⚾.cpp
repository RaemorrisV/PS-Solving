#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int n;
vector<vector<int>> player_perform(51);
deque<int> order;
bool visited[10];
int score = 0;
int MAX = -1;
int outcount = 0;
bool location[4];
void progress(int num)
{
    if (num == 4) //홈런일때
    {
        score++; //자기 자신
        for (int i = 1; i < 4; i++)
        {
            if (location[i])
            {
                score++;
                location[i] = false;
            }
        }
    }
    else //진루타일때
    {
        for (int i = 3; i >= 0; i--)
        {
            if (location[i])
            {
                if (i + num >= 4)
                {
                    score++;
                    location[i] = false;
                }
                else
                {
                    location[i] = false;
                    location[i + num] = true;
                }
            }
        }
        location[num] = true;
    }
}
int simulation() //얻은 점수를 반환시키는 시뮬레이션
{
    deque<int> order_player = order;
    for (int i = 1; i <= n; i++)
    {
        while (outcount != 3)
        {
            if (player_perform[i][order_player[0] - 1] == 0)
            {
                outcount++;
                int change = order_player.front();
                order_player.pop_front();
                order_player.push_back(change);
            }
            else
            {
                if (player_perform[i][order_player[0] - 1] == 1)
                {
                    progress(1);
                    int change1 = order_player.front();
                    order_player.pop_front();
                    order_player.push_back(change1);
                }
                else if (player_perform[i][order_player.front() - 1] == 2)
                {
                    progress(2);
                    int change2 = order_player.front();
                    order_player.pop_front();
                    order_player.push_back(change2);
                }
                else if (player_perform[i][order_player.front() - 1] == 3)
                {
                    progress(3);
                    int change3 = order_player.front();
                    order_player.pop_front();
                    order_player.push_back(change3);
                }
                else if (player_perform[i][order_player.front() - 1] == 4)
                {
                    progress(4);
                    int change4 = order_player.front();
                    order_player.pop_front();
                    order_player.push_back(change4);
                }
            }
        }
        memset(location, 0, sizeof(location));
        outcount = 0;
    }
    return score;
}
void dfs(int s)
{
    order.push_back(s);
    if (order.size() == 9)
    {
        MAX = max(MAX, simulation());
        score = 0;
        return;
    }
    if (order.size() == 3)
    {
        visited[1] = true;
        dfs(1);
        visited[1] = false;
        order.pop_back();
        return;
    }
    for (int i = 2; i <= 9; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
            visited[i] = false;
            order.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int in;
            cin >> in;
            player_perform[i].push_back(in);
        }
    }
    for (int i = 2; i <= 9; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
            visited[i] = false;
            order.pop_back();
        }
    }
    cout << MAX << '\n';
    return 0;
}