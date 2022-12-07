#include <iostream>
#include <vector>
using namespace std;

int k;
int sum = 0;
int in;
vector<int> li;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> in;
        if (in == 0)
        {
            li.pop_back();
        }
        else
        {
            li.push_back(in);
        }
    }
    for (int i = 0; i < li.size(); i++)
    {
        sum += li[i];
    }
    cout << sum << '\n';
    return 0;
}