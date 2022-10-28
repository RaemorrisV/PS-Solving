#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int arr1[26];
int arr2[26];
int n;
string str;
int ans = 0;
int len1, len2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (i == 0)
			{
				arr1[str[j] - 'A']++;
				len1 = str.length();
			}
			else
			{
				arr2[str[j] - 'A']++;
			}
		}
		if (i > 0)
		{
			len2 = str.length();
			int cnt = 0;
			if (len1 == len2)
			{
				for (int j = 0; j < 26; j++)
				{
					cnt += abs(arr1[j] - arr2[j]);
				}
				if (cnt <= 2)
				{
					ans++;
				}
				memset(arr2, 0, sizeof(arr2));
			}
			else
			{
				for (int j = 0; j < 26; j++)
				{
					cnt += abs(arr1[j] - arr2[j]);
				}
				if (cnt == 1)
				{
					ans++;
				}
				memset(arr2, 0, sizeof(arr2));
			}
		}
	}
	cout << ans << endl;
	return 0;
}