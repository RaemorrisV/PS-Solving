#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> input;
int n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }
    if (next_permutation(input.begin(), input.end()))
    {
        for (int i = 0; i < n; i++)
        {
            cout << input[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }
    return 0;
}