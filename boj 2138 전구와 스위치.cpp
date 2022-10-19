#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> light;
vector<int> ans;
int n;
string input;
int cnt = 0;
int MIN = 100001;
int main()
{
    cin >> n;
    cin >> input;
    for (int i = 0; i < n; i++)
    {
        light.push_back(input[i] - '0');
    }
    cin >> input;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(input[i] - '0');
    }
    vector<int> temp = light;
    if (temp[0] == 1)
    {
        temp[0] = 0;
    }
    else
    {
        temp[0] = 1;
    }
    if (temp[1] == 1)
    {
        temp[1] = 0;
    }
    else
    {
        temp[1] = 1;
    }
    cnt++;
    for (int i = 1; i < n; i++) // 1번을 켰을때
    {
        if (temp[i - 1] != ans[i - 1]) //같이 않았을 경우에만
        {
            if (i != n - 1)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (temp[i + j] == 1)
                    {
                        temp[i + j] = 0;
                    }
                    else
                    {
                        temp[i + j] = 1;
                    }
                }
            }
            else
            {
                for (int j = -1; j <= 0; j++)
                {
                    if (temp[i + j] == 1)
                    {
                        temp[i + j] = 0;
                    }
                    else
                    {
                        temp[i + j] = 1;
                    }
                }
            }
            cnt++;
        }
    }
    if (temp == ans)
    {
        MIN = min(MIN, cnt);
        // cnt = 0;
    }
    cnt = 0;
    vector<int> temp1 = light;
    for (int i = 1; i < n; i++) // 1번을 껏을때
    {
        if (temp1[i - 1] != ans[i - 1]) //같이 않았을 경우에만
        {
            if (i != n - 1)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (temp1[i + j] == 1)
                    {
                        temp1[i + j] = 0;
                    }
                    else
                    {
                        temp1[i + j] = 1;
                    }
                }
            }
            else
            {
                for (int j = -1; j <= 0; j++)
                {
                    if (temp1[i + j] == 1)
                    {
                        temp1[i + j] = 0;
                    }
                    else
                    {
                        temp1[i + j] = 1;
                    }
                }
            }
            cnt++;
        }
    }
    if (temp1 == ans)
    {
        MIN = min(MIN, cnt);
    }

    if (MIN != 100001)
    {
        cout << MIN << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}