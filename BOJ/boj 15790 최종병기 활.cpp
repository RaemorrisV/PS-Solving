#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int>cut_idx;
vector<int>diff;
int ans;
bool decision_fun(int mid)
{
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int index = i;
		total = 0;
		for (int j = i + 1; j < m + i + 1; j++)
		{
			if (cut_idx[j] - cut_idx[index] >= mid)
			{
				total++;
				index=j;
			}
		}
		if (total >= k)return true;
	}
	return false;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cut_idx.push_back(a);
		cut_idx.push_back(a + n);
	}
	sort(cut_idx.begin(), cut_idx.end());
	int s = 1;
	int e = n;
	while (s <= e)
	{
		int mid = (s + e) / 2; //���� ���� ������ ����  mid ��� �Ѵٸ�
		if (decision_fun(mid))//�̰ɷ� ���� �ϴٸ�
		{
			s = mid + 1;
			ans = mid;
		}
		else
		{
			e = mid - 1;
		}
	}
	if (ans == 0)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}