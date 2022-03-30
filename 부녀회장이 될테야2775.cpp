#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;
int apt[1000][15];
int main()
{
	int test;
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		int k, n;
		cin >> k >> n;
		for (int b = 0; b < 15; b++)
		{
			apt[0][b] = b;
		}

		for (int j = 1; j <= k; j++)//층
		{
			for (int q = 1; q <= n; q++)//호수
			{
				for (int w = 1; w <= q; w++)
				{
					apt[j][q] += apt[j - 1][w];
				}
			}
		}
		cout << apt[k][n] << endl;

		memset(apt, 0, sizeof(apt));
	}
	return 0;
}