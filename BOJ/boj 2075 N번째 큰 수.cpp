#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n;
int input;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            if (q.size() < n)
            {
                q.push(input);
            }
            else if (q.size() == n)
            {
                if (q.top() < input)
                {
                    q.pop();
                    q.push(input);
                }
            }
        }
    }
    cout << q.top() << '\n';
    return 0;
}