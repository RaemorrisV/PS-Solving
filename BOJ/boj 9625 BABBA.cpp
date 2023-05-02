#include <iostream>

using namespace std;


int dpA[46];
int dpB[46];
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dpA[0] = 1;
	dpB[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dpA[i] = dpA[i - 1] + dpA[i - 2];
		dpB[i] = dpB[i - 1] + dpB[i - 2];
	}
	cout << dpA[n] << " " << dpB[n] << '\n';
	return 0;
}