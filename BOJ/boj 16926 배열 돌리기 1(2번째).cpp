#include <iostream>

using namespace std;

int n, m, r; //행 열
int arr[300][300];
void rotate()
{
    int size;
    if(n>=m)size=m;
    else size=n;
    for (int k = 0; k < size / 2; k++)
    {
        int temp = arr[k][k];
        for (int i = k; i < m - 1 - k; i++) //북
        {
            arr[k][i] = arr[k][i + 1];
        }
        for (int i = k; i < n - 1 - k; i++) //동
        {
            arr[i][m - 1 - k] = arr[i + 1][m - 1 - k];
        }
        for (int i = m - 1 - k; i > k; i--) //남
        {
            arr[n - 1 - k][i] = arr[n - 1 - k][i - 1];
        }
        for (int i = n - 1 - k; i > k; i--) //서
        {
            arr[i][k] = arr[i - 1][k];
        }
        arr[k + 1][k] = temp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        rotate();
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