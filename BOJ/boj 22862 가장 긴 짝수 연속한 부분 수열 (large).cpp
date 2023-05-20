#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int n, k;
int ans = 0;
int odd;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int s = 1;
	int e = 1;
	int even = 0;
	if (arr[1] % 2 == 1)odd++;
	if (arr[1] % 2 == 0)even++;
	ans = max(ans, even);
	while (s<= e && e < n)
	{
		if (odd > k)//이러면 더 못옮김
		{
			if (arr[s] % 2 == 1)odd--;
			else if (arr[s] % 2 == 0)even--;
			s++;
		}
		else
		{
			e++;
			if (arr[e] % 2 == 1)odd++;
			else if (arr[e] % 2 == 0)even++;
		}
		if (odd <= k)
		{
			ans = max(ans, even);
			//cout << "중간 출력 " << s << " " << e << " " << odd <<" "<<even << endl;
		}
	}

	cout << ans << '\n';
	return 0;
}
