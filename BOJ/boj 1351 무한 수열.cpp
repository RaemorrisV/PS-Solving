#include <iostream>
#include <unordered_map>

using namespace std;
long long n, p, q;
unordered_map<long long, long long>check;
long long dfs(long long want, long long left, long long right)
{
	if (check[want]!=0)return check[want];
	check[want] = dfs(want / left, left, right) + dfs(want / right, left, right);
	return check[want];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> p >> q;
	check[0] = 1;
	cout << dfs(n, p, q) << '\n';
	return 0;
}