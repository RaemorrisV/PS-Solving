#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

int n;
int offset = 1;
int indextree[1048576];
struct player {
	int cur;
	int order;
};
vector<player>play;
int ans[500001];
bool compare(player a, player b)
{
	if (a.order > b.order)return true;
	return false;
}
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x*2] + indextree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx)
{
	idx += offset - 1;
	indextree[idx]++;
	update(idx);
}
int query(int end)
{
	int start = offset;
	end += offset - 1;
	int res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)res += indextree[start++];
		if (end % 2 == 0)res += indextree[end--];
		start /= 2;
		end /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		play.push_back({ i + 1,a });
	}
	sort(play.begin(), play.end(), compare);
	for (int i = 0; i < n; i++)
	{
		make_tree(play[i].cur);
		ans[play[i].cur] = query(play[i].cur);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}