#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> card;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        card.push_back(in);
    }
    sort(card.begin(), card.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int in;
        cin >> in;
        if (card[lower_bound(card.begin(), card.end(), in) - card.begin()] == in)
        {
            cout << "1" << " ";
        }
        else
        {
            cout << "0" << " ";
        }
    }
    cout << '\n';
    return 0;
}