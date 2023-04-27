#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, ans;
int check = 1;
unordered_map<string, int>input;
unordered_map<string, int>output;
vector<string>arr;
void simulation()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (output[arr[i]] > output[arr[j]])
			{
				ans++;
				break;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		input[a] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		output[a] = input[a];
		arr.push_back(a);
	}
	simulation();
	cout << ans << '\n';
	return 0;
}