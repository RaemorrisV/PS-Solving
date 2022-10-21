#include <iostream>
#include <vector>

using namespace std;
vector<long long>arr;
int n, m;
long long input;
long long cnt[10000];
long long sum = 0;
long long ans = 0;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		sum += input;
		cnt[sum % m]++;
		if (sum % m == 0)ans++;
		//arr.push_back(input);
	}
	for (int i = 0; i < m; i++)
	{
		ans += (cnt[i] * (cnt[i] - 1)) / 2;
	}
	cout << ans << '\n';
	return 0;
}