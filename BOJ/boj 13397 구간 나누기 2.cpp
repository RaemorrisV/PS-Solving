#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int t_mi = 10001;
int t_ma;
int arr[5001];
bool check(int center)
{
	int c = 1;
	int MIN = arr[1];
	int MAX = arr[1];
	for(int i=2;i<=n;i++)
	{ 
		MIN = min(MIN, arr[i]);
		MAX = max(MAX, arr[i]);
		if (MAX - MIN > center)
		{
			MAX = arr[i];
			MIN = arr[i];
			c+=1;
		}
	}
	//cout <<"D " << center << " " << c << "\n";
	if (c <= m)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		t_mi = min(arr[i], t_mi);
		t_ma = max(arr[i], t_ma);
	}
	int s = 0;
	int e = t_ma - t_mi;
	while (s<=e)
	{
		int mid = (s + e) / 2;
		if (check(mid)) //되면 줄여도됨
		{
			ans = mid;
			e = mid - 1;
		}
		else //안되면 늘려야지
		{
			s = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}