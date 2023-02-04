#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

long long indextree[524288];
long long ans = 1;
int cnttree[524288];
int n, offset;
long long MAX = -2;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x * 2] + indextree[x * 2 + 1];
		cnttree[x] = cnttree[x * 2] + cnttree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	indextree[idx] += val;
	cnttree[idx]++;
	update(idx);
}
long long query_cnt(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	long long res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)res += cnttree[start++];
		if (end % 2 == 0)res += cnttree[end--];
		start /= 2;
		end /= 2;
	}
	return res;
}
long long query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	long long res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			res += indextree[start];
			start++;
		}
		if (end % 2 == 0)
		{
			res += indextree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (offset = 1; offset < 200000; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		long long input;
		cin >> input;
		make_tree(input + 1, input + 1);
		MAX = max(MAX, input + 1);
		if (i > 1)
		{
			long long under = query_cnt(1, input);
			long long upper = query_cnt(input + 2, MAX);
			long long temp1 = (under) * (input + 1) - query(1, input);
			temp1 %= MOD;
			//cout << "temp2 디버그 " <<under<<" "<< upper << " " << MAX << " " << query(input + 1, MAX - 1) << endl;
			long long temp2 = query(input + 2, MAX) - (upper) * (input + 1);
			temp2 %= MOD;
			//cout << "디버그 출력 " << temp1 << " " << temp2 << endl;
			ans = (((temp1 + temp2) % MOD) * (ans % MOD)) % MOD;
			//cout << "sad" << ans << endl;
		}
	}
	cout << ans << '\n';
	return 0;
}