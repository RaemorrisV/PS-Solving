#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
bool is_prime[1001];
int n, input;
int ans = 0;
void prime_disting()
{
    for (int i = 2; i <= sqrt(1000); i++)
    {
        for (int j = i * 2; j <= 1000; j += i)
        {
            if (is_prime[j])
            {
                is_prime[j] = false;
            }
        }
    }
    is_prime[1] = false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(is_prime, 1, sizeof(is_prime));
    cin >> n;
    prime_disting();
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (is_prime[input])
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}