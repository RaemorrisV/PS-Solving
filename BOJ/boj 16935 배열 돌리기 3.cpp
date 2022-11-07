#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;
int n, m, r; //행 열 연산의수
void one()
{
    vector<int> temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
void two()
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp.push_back(arr[i][j]);
        }
        reverse(temp.begin(), temp.end());
        arr[i] = temp;
        temp.clear();
    }
}
void three()
{
    vector<vector<int>> temp(101);
    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            temp[j].push_back(arr[i][j]);
        }
    }
    arr.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        arr[i] = temp[i];
    }
    swap(n, m);
}
void four()
{
    vector<vector<int>> temp(101);
    for (int j = 0; j < n; j++) // 8 6
    {
        for (int i = m - 1; i >= 0; i--)
        {
            temp[j].push_back(arr[j][i]);
        }
    }
    vector<vector<int>> tmp(m, vector<int>(n));
    for (int i = 0; i < n; i++) // 8
    {
        for (int j = 0; j < m; j++) // 6
        {
            tmp[j][i] = temp[i][j];
        }
    }
    arr = tmp;
    swap(n, m); // 8 6
}
void five()
{
    vector<vector<int>> temp(101);
    for (int i = 0; i < n / 2; i++) // 1 사분면 저장
    {
        for (int j = 0; j < m / 2; j++)
        {
            temp[i].push_back(arr[i][j]);
        }
    }
    for (int i = n / 2; i < n; i++) // 4 사분면
    {
        for (int j = 0; j < m / 2; j++)
        {
            arr[i - n / 2][j] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) // 3
    {
        for (int j = m / 2; j < m; j++)
        {
            arr[i][j - m / 2] = arr[i][j];
        }
    }
    for (int i = 0; i < n / 2; i++) // 2 >>3
    {
        for (int j = m / 2; j < m; j++)
        {
            arr[i + n / 2][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n / 2; i++) // 2
    {
        for (int j = m / 2; j < m; j++)
        {
            arr[i][j] = temp[i][j - m / 2];
        }
    }
}
void six()
{
    vector<vector<int>> temp(101);
    for (int i = 0; i < n / 2; i++) // 1 사분면 저장
    {
        for (int j = 0; j < m / 2; j++)
        {
            temp[i].push_back(arr[i][j]);
        }
    }
    for (int i = 0; i < n / 2; i++) // 2
    {
        for (int j = m / 2; j < m; j++)
        {
            arr[i][j - m / 2] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) // 3
    {
        for (int j = m / 2; j < m; j++)
        {
            arr[i - n / 2][j] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) // 4 사분면
    {
        for (int j = 0; j < m / 2; j++)
        {
            arr[i][j + m / 2] = arr[i][j];
        }
    }
    for (int i = n / 2; i < n; i++) // 4 사분면
    {
        for (int j = 0; j < m / 2; j++)
        {
            arr[i][j] = temp[i - n / 2][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> r;
    arr.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            one();
        }
        else if (c == 2)
        {
            two();
        }
        else if (c == 3)
        {
            three();
        }
        else if (c == 4)
        {
            four();
        }
        else if (c == 5)
        {
            five();
        }
        else if (c == 6)
        {
            six();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
