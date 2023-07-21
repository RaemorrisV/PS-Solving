#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

char wheel[25];
int n, k;
bool flag;
unordered_map<char, bool>checking;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	int startIndex = 0;
	for (int i = 0; i < k; i++)
	{
		int s;
		char word;
		cin >> s >> word;
		s = s % n;
		if (flag)continue;
		int temp = startIndex - s;
		if (temp < 0)temp += n;
		if (temp < 0 || temp > (n - 1))
		{
			flag = true;
			continue;
		}
		if (wheel[temp] != '\0')
		{
			if (wheel[temp] != word)
			{
				flag = true;
				continue;
			}
		}
		else
		{
			if (checking[word])
			{
				flag = true;
				continue;
			}
			checking[word] = true;
			wheel[temp] = word;
		}
		startIndex = temp;
	}
	if (flag)
	{
		cout << "!" << '\n';
	}
	else
	{
		int count = 0;
		while (1)
		{
			if (count == n)break;
			if (wheel[startIndex] == '\0')cout << "?";
			else cout << wheel[startIndex];
			count++;
			startIndex = startIndex + 1 > n - 1 ? startIndex + 1 - n : startIndex + 1;
		}
		cout << "\n";
	}
	return 0;
}