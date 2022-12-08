#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
bool prime[1001];
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n >> k;
    fill(prime, prime + 1001, 1);
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cnt++;
            if (cnt == k)
            {
                cout << i << '\n';
                exit(0);
            }
            for (int j = 2 * i; j <= n; j += i)
            {
                if (prime[j])
                {
                    cnt++;
                    prime[j] = false;
                    if (cnt == k)
                    {
                        cout << j << '\n';
                        exit(0);
                    }
                }
            }
        }
    }
    return 0;
}