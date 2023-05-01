#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct card {
	char color;
	int num;
};
vector<card>arr;
int c[4];// R, B, Y, G 순서대로
int ans = 0;
unordered_map<int, int>same_num;
bool compare(card a, card b)
{
	return a.num < b.num;
}
void check_color()
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i].color == 'R')c[0]++;
		else if (arr[i].color == 'B')c[1]++;
		else if (arr[i].color == 'Y')c[2]++;
		else if (arr[i].color == 'G')c[3]++;
	}
}
bool consist()
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i].num + 1 != arr[i + 1].num)return false;
	}
	return true;
}
int same()
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i].num == arr[i + 1].num)return arr[i].num;
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		char a;
		int b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end(), compare);
	check_color();
	for (int i = 0; i < 5; i++)
	{
		same_num[arr[i].num]++;
	}
	//5장이 모두 같은색 연속
	for (int i = 0; i < 5; i++)
	{
		if (c[i] == 5 && consist())
		{
			ans = max(ans, arr[4].num + 900);
		}
		if (c[i] == 5)
		{
			ans = max(ans, arr[4].num + 600);
		}
	}
	//4장의 숫자가 같음
	for (auto it : same_num)
	{
		if (it.second == 4)
		{
			ans = max(ans, it.first + 800);
		}
	}
	//3 2
	for (auto it : same_num)
	{
		if (it.second == 3)
		{
			for (auto it2 : same_num)
			{
				if (it2.second == 2)
				{
					ans = max(ans, it.first * 10 + it2.first + 700);
				}
			}
			ans = max(ans, it.first + 400);
		}
	}
	if (consist())
	{
		ans = max(ans, arr[4].num + 500);
	}
	for (auto it : same_num)
	{
		if (it.second == 2)
		{
			for (auto it2 : same_num)
			{
				if (it2.second == 2 && it2 != it)
				{
					ans = max(ans, max(it.first, it2.first) * 10 + min(it.first, it2.first) + 300);
				}
			}
			ans = max(ans, it.first + 200);
		}
	}
	if (ans == 0)ans = arr[4].num + 100;
	cout << ans << '\n';
	return 0;
}