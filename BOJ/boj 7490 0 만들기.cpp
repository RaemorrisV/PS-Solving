#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>arr;
vector<string>ans;
int t, n;
void dfs(int s)
{
	ans.push_back(to_string(s));
	if (s == n)
	{
		int sum = 0;
		vector<string>temp;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] == " ")
			{

				string tmp = temp.back() + ans[i + 1];
				temp.pop_back();
				temp.push_back(tmp);
				i++;
			}
			else
			{
				temp.push_back(ans[i]);
			}
		}
		sum = stoi(temp[0]);
		for (int i = 1; i < temp.size(); i++)
		{
			if (temp[i] == "+")
			{
				sum += stoi(temp[i + 1]);
			}
			else if (temp[i] == "-")
			{
				sum -= stoi(temp[i + 1]);
			}
		}
		if (sum == 0)
		{
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	ans.push_back(" ");
	dfs(s + 1);
	ans.pop_back();
	ans.pop_back();
	ans.push_back("+");
	dfs(s + 1); //»¬»ù¿¬»ê
	ans.pop_back();
	ans.pop_back();
	ans.push_back("-");
	dfs(s + 1); //°ø¹é¿¬»ê
	ans.pop_back();
	ans.pop_back();
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			arr.push_back(j);
		}
		dfs(arr[0]);
		cout << '\n';
		arr.clear();
		ans.clear();
	}
	return 0;
}