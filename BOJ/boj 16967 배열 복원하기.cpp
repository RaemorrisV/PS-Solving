#include <iostream>

using namespace std;

int h, w, x, y;
int arr[600][600];
int a[300][300];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h + x; i++)
    {
        for (int j = 0; j < w + y; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i >= x && j >= y)
            {
                arr[i][j] -= arr[i - x][j - y];
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}