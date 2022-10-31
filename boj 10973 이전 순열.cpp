#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[10000];
int MAX = 0;
bool flag;
bool compare(int a, int b)
{
    if (a > b)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i - 1] > arr[i])
        {
            int index;
            for (int j = i; j < n; j++)
            {
                if (arr[i - 1] > arr[j])
                {
                    MAX = max(MAX, arr[j]);
                    if (MAX == arr[j])
                    {
                        index = j;
                    }
                }
            }
            swap(arr[index], arr[i - 1]);
            sort(arr + i, arr + n, compare);
            flag = true;
            break;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }
    return 0;
}