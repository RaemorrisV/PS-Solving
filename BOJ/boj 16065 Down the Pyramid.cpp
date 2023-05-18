#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>arr;
vector<int>diff;
vector<int>odd_diff;
vector<int>even_diff;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	diff.push_back(0);
	int dif = arr[0] - diff.back();
	odd_diff.push_back(0);
	diff.push_back(dif);
	even_diff.push_back(dif);
	for (int i = 1; i < n; i++)
	{
		int dif = arr[i] - diff.back();
		diff.push_back(dif);
		if((i)%2==1)//È¦¼ö
		{ 
			odd_diff.push_back(dif);
		}
		else if ((i) % 2 == 0)//Â¦¼ö¸é
		{
			even_diff.push_back(dif);
		}
	}
	sort(odd_diff.begin(), odd_diff.end());
	sort(even_diff.begin(), even_diff.end());
	//cout << odd_diff[0] << " " << even_diff[0] << '\n';
	if (abs(odd_diff[0]) <= even_diff[0])
	{
		cout << even_diff[0] - abs(odd_diff[0]) +1  << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
	return 0;
}