#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int a, p;
unordered_map<int, bool>check;
vector<int>arr;
int n_pow(string num)
{
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
	{
		int want = (num[i] - '0');
		int powval = 1;
		for (int j = 0; j < p; j++)
		{
			powval *= want;
		}
		sum += powval;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> p;
	arr.push_back(a);
	check[a] = true;
	while (1)
	{
		int n_num = n_pow(to_string(arr[arr.size() - 1]));
		if (check[n_num])
		{
			cout << find(arr.begin(), arr.end(), n_num) - arr.begin() << '\n';
			break;
		}
		check[n_num] = true;
		arr.push_back(n_num);
	}
	return 0;
}