#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int cnt = 0;
	set<string> s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		s.insert(word);
	}
	for (int i = 0; i < m; i++)
	{
		string word;
		cin >> word;
		if (s.find(word) != s.end())
		{
		  cnt++;
		}
		
	}
	cout<< cnt<< "\n";
	return 0;
}