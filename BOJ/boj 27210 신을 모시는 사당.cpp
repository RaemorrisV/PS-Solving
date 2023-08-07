#include <iostream>
#include <algorithm>

using namespace std;

int rdp[100001];
int ldp[100001];
int side[100001];
int n;
int ans = 1;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> side[i];
	}
	if (side[1] == 1)ldp[1] = 1;
	if (side[1] == 2)rdp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (side[i] == 1)//왼쪽
		{
			ldp[i] = ldp[i - 1] + 1;
			rdp[i] = max(rdp[i - 1] - 1, 0);
		}
		else//오른쪽
		{
			rdp[i] = rdp[i - 1] + 1;
			ldp[i] = max(ldp[i - 1] - 1, 0);
		}
		ans = max({ ans,ldp[i],rdp[i] });
	}
	cout << ans << '\n';
	return 0;
}
