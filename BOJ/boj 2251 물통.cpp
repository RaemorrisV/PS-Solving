#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>ans;
int max_c[3];

bool visited[201][201][201];
void dfs(int a,int b,int c)
{
	if (visited[a][b][c])return;
	visited[a][b][c] = true;
	if (a == 0)
	{
		ans.push_back(c);
	}
    //a > b 
	if (a + b > max_c[1]) {
		dfs(a+b-max_c[1], max_c[1], c);
	}
	else {
		dfs(0, a+b, c);
	}
	//a > c
	if (a + c > max_c[2]) {
		dfs(a + c - max_c[2], b, max_c[2]);
	}
	else {
		dfs(0, b, a+c);
	}
	// b > c
	if (b + c > max_c[2]) {
		dfs(a, b+c-max_c[2], max_c[2]);
	}
	else {
		dfs(a, 0, b+c);
	}
	//b > a
	if (b + a > max_c[0]) {
		dfs(max_c[0], b + a - max_c[0], c);
	}
	else {
		dfs(b+a, 0, c);
	}
	//c > a 
	if (c+a > max_c[0]) {
		dfs(max_c[0], b, c + a - max_c[0]);
	}
	else {
		dfs(c+a, b, 0);
	}
	//c > b
	if (c + b > max_c[1]) {
		dfs(a, max_c[1], c + b - max_c[1]);
	}
	else {
		dfs(a, c+b, 0);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 3; i++)
	{
		cin >> max_c[i];
	}
	dfs(0, 0, max_c[2]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}