#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans;
vector<int>use;
bool check(int mid)
{
	int count = 0;
	int money = mid;
	for (int i = 0; i < n; i++)
	{
		if (mid < use[i])return false;
		money -= use[i];
		if (money < 0) //음수라면
		{
			count++;
			money = mid - use[i];
		}
	}
	count++;
	if (count <= m)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		use.push_back(input);
	}
	int s = 1;
	int e = 1000000000;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (check(mid)) //값을 내려야됨
		{
			ans = mid;
			e = mid - 1;
		}
		else //올려야됨 
		{
			s = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
