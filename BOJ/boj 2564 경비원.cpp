#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, n, ans;
vector<pair<int, int>>index;
pair<int, int>donggun;
int clockwise(int i)
{
	int sum = 0;
	int nx = donggun.first; //행
	int ny = donggun.second; //열
	while (1)
	{
		if (!(nx == index[i].first && ny == index[i].second) == false)break;
		sum++;
		if (ny == 0 && nx > 0)
		{
			nx -= 1;
		}
		else if (ny == c && nx < r)
		{
			nx += 1;
		}
		else if (nx == 0 && ny < c)
		{
			ny += 1;
		}
		else if (nx == r && ny > 0)
		{
			ny -= 1;
		}
	}
	return sum;
}
int counterclockwise(int i)
{
	int sum = 0;
	int nx = donggun.first; //행
	int ny = donggun.second; //열
	while (1)
	{
		if (!(nx == index[i].first && ny == index[i].second) == false)break;
		sum++;
		if (ny == 0 && nx < r)
		{
			nx += 1;
		}
		else if (ny == c && nx > 0)
		{
			nx -= 1;
		}
		else if (nx == 0 && ny > 0)
		{
			ny -= 1;
		}
		else if (nx == r && ny < c)
		{
			ny += 1;
		}
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> c >> r >> n;
	for (int i = 0; i <= n; i++)
	{
		int four;
		int far;
		cin >> four;
		if (i == n)
		{
			if (four == 1)
			{
				cin >> far;
				donggun = { 0,far };
			}
			else if (four == 2)
			{
				cin >> far;
				donggun = { r,far };
			}
			else if (four == 3)
			{
				cin >> far;
				donggun = { far,0 };
			}
			else if (four == 4)
			{
				cin >> far;
				donggun = { far,c };
			}
		}
		else
		{
			if (four == 1)
			{
				cin >> far;
				index.push_back({ 0,far });
			}
			else if (four == 2)
			{
				cin >> far;
				index.push_back({ r,far });
			}
			else if (four == 3)
			{
				cin >> far;
				index.push_back({ far,0 });
			}
			else if (four == 4)
			{
				cin >> far;
				index.push_back({ far,c });
			}
		}
	}
	for (int i = 0; i < index.size(); i++)
	{
		//cout << counterclockwise(i) << endl;
		ans += min(counterclockwise(i), clockwise(i));
	}
	cout << ans << '\n';
	return 0;
}