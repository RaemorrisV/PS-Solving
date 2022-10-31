#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[10000];
int MAX = 0;
bool flag;
bool compare(int a, int b)
{
    if (a > b)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (prev_permutation(arr, arr + n))
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
