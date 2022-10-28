#include <iostream>
#include <queue>
using namespace std;
int t, n, want, want_cost;
queue<pair<int, int>> q;
priority_queue<int> Q;
int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> want;
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            if (j == want)
                want_cost = input;
            q.push({j, input});
            Q.push(input);
        }
        int k = 1;
        while (!q.empty())
        {
            if (q.front().first == want && q.front().second == Q.top())
            {
                // k++;
                cout << k << endl;
                break;
            }
            else
            {
                if (Q.top() > q.front().second)
                {
                    q.push({q.front().first, q.front().second});
                    q.pop();
                }
                else if (Q.top() == q.front().second)
                {
                    k++;
                    q.pop();
                    Q.pop();
                }
            }
        }
        while (!q.empty())
            q.pop();
        while (!Q.empty())
            Q.pop();
    }
    return 0;
}