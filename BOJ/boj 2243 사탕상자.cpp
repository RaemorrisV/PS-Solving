#include <iostream>

using namespace std;

int n;
long long indextree[2097152];
int offset = 1;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x * 2] + indextree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	indextree[idx] += val;
	update(idx);
}
int find_ans(int rank) //위에서 내려가면서 찾아야됨
{
	int root = 1;
	int depth = 1;
	while (depth != 21)
	{
		if (rank > indextree[root * 2])//오른쪽 서브트리로 보내야됨
		{
			rank -= indextree[root * 2];
			root = root * 2 + 1;
		}
		else //왼쪽 서브트리로 보내는게 맞음
		{
			root *= 2;
		}
		depth++;
	}
	make_tree(root + 1 - offset, -1);
	return root + 1 - offset;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (offset = 1; offset < 1000000; offset *= 2);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			cout << find_ans(b) << '\n';
		}
		else
		{
			cin >> b >> c;
			make_tree(b,c);
		}
	}
	return 0;
}