#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
bool prime[1000001];
vector<int> prime_num;
void checking()
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
        {
            prime_num.push_back(i);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(prime, 1, sizeof(prime));
    cin >> m >> n;
    checking();
    for (int i = 0; i < prime_num.size(); i++)
    {
        if (prime_num[i] >= m && prime_num[i] <= n)
        {
            cout << prime_num[i] << '\n';
        }
    }
    return 0;
}