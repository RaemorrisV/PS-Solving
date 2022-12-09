#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string in;
int max_x = 0;
int min_x = 0;
int max_y = 0;
int min_y = 0;
int dx[4] = {0, 0, -1, 1}; //북 서 남 동
int dy[4] = {1, -1, 0, 0}; //
int dir = 0;               //북 서 남 동 0 1 2 3 순   왼: 북>서 서>남 남>동 동>북  +1 %4 오: 북>동 동>남 남>서 서>북 +3*4
int s_x = 0;
int s_y = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> in;
        for (int j = 0; j < in.length(); j++)
        {
            if (in[j] == 'F')
            {
                if (dir == 0) //북
                {
                    s_y += 1;
                }
                else if (dir == 1) //서
                {
                    s_x -= 1;
                }
                else if (dir == 2) //남
                {
                    s_y -= 1;
                }
                else //동
                {
                    s_x += 1;
                }
                max_x = max(max_x, s_x);
                min_x = min(min_x, s_x);
                max_y = max(max_y, s_y);
                min_y = min(min_y, s_y);
            }
            else if (in[j] == 'B')
            {
                if (dir == 0) //북
                {
                    s_y -= 1;
                }
                else if (dir == 1) //서
                {
                    s_x += 1;
                }
                else if (dir == 2) //남
                {
                    s_y += 1;
                }
                else //동
                {
                    s_x -= 1;
                }
                max_x = max(max_x, s_x);
                min_x = min(min_x, s_x);
                max_y = max(max_y, s_y);
                min_y = min(min_y, s_y);
            }
            else if (in[j] == 'L')
            {
                dir = (dir + 1) % 4;
            }
            else if (in[j] == 'R')
            {
                dir = (dir + 3) % 4;
            }
        }
        cout << (max_x - min_x) * (max_y - min_y) << '\n';
        max_x = 0;
        min_x = 0;
        max_y = 0;
        min_y = 0;
        dir = 0;
        s_x = 0;
        s_y = 0;
    }
    return 0;
}