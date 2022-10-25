#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n;
bool prime[4000001];
vector<int> prime_num;
int ans = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(prime, 1, sizeof(prime));
    if (n == 1)
    {
        cout << "0" << '\n';
        return 0;
    }
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

    //이제 투포인터 사용
    int s = 0;
    int e = 0;
    int sum = prime_num[0];
    while (s <= e)
    {
        if (sum >= n)
        {
            if (sum == n)
            {
                ans++;
            }
            sum -= prime_num[s++];
        }
        else if (sum < n)
        {
            if (prime_num[e] != prime_num.back())
            {
                sum += prime_num[++e];
            }
            else
            {
                s++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}