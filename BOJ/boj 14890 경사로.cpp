#include <iostream>
#include <cstring>
using namespace std;
int n, l;
int map[201][201];
int map2[201][201];
bool possible[101][101];
int ans = 0;
bool impossible;
bool valide(int r)
{
    for (int i = 1; i <= n; i++)
    {
        if (possible[r][i] == false)
            return false;
    }
    return true;
}
void row(int a[][201])
{
    for (int i = 1; i <= n; i++)
    {
        impossible = false;
        for (int j = 1; j <= n; j++)
        {
            if (impossible == false)
            {
                if (a[i][j] == a[i][j + l] - 1) //첫번째 경우
                {
                    if (possible[i][j] == false)
                    {
                        for (int k = 0; k < l; k++)
                        {
                            if (a[i][j + k] == a[i][j + l] - 1)
                            {
                                possible[i][j + k] = true;
                            }
                            else
                            {
                                impossible = true;
                                break;
                            }
                        }
                        j += l - 1;
                    }
                    else
                    {
                        impossible = true;
                        break;
                    }
                }
                else if (a[i][j] - 1 == a[i][j + 1]) // 두번째 경우
                {
                    if (j + l <= n && possible[i][j + l] == false)
                    {
                        possible[i][j] = true;
                        for (int k = 1; k <= l; k++)
                        {
                            if (a[i][j + k] == a[i][j] - 1)
                            {
                                possible[i][j + k] = true;
                            }
                            else
                            {
                                impossible = true;
                                break;
                            }
                        }
                        j += l - 1;
                    }
                    else
                    {
                        impossible = true;
                        break;
                    }
                }
                else if (a[i][j] == a[i][j + 1]) //인접이 높이가 같을 경우
                {
                    possible[i][j] = true;
                }
                else //어디에도 속하지않음
                {
                    impossible = true;
                }
            }
            else
            {
                break;
            }
        }
        if (valide(i) && impossible == false)
        {
            ans++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            map2[j][i] = map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        map[i][n + 1] = map[i][n];
        map2[i][n + 1] = map2[i][n];
    }
    row(map);
    memset(possible, 0, sizeof(possible));
    row(map2);
    cout << ans << '\n';

    return 0;
}