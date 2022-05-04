#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int cnt[8001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int num=0;
	cin >> n;
	int aver = 0;
	int mean = 0;
	int mode = 0;
	int range = 0;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		cnt[array[i] + 4000]++;
	}
	int max = *max_element(cnt, cnt + 8001);

	for (int i = 0; i < 8001; i++)
	{
		if (max == cnt[i])
		{
			num++;
		}
	}
	if (num == 1)
	{
		for (int i = 0; i < 8001; i++)
		{
			if (max == cnt[i])
			{
				mode = i-4000;
			}
		}
	}
	else if (num >= 2)
	{
		int s = 0;
		for (int i = 0; i < 8001; i++)
		{
			if (max == cnt[i])
			{
				s++;
				if (s == 2)
				{
					mode = i - 4000;
				}
			}
		}

	}
	sort(array, array+n);
	for (int i = 0; i < n; i++)
	{
		aver += array[i];
	}
	aver = round((float)aver/n);
	mean = array[(n / 2)];
	range = array[n - 1] - array[0];
	cout << aver << '\n'<<mean<<'\n'<< mode <<'\n'<< range<<'\n';
	delete[] array;
	return 0;
}