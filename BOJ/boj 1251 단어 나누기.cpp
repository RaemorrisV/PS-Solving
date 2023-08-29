#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string word;
vector<string>ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> word;
	for (int i = 0; i < word.length()-2; i++)
	{
		for (int j = i + 2; j < word.length(); j++)
		{
			int sIndex = i;
			int eIndex = j;
			string first = word.substr(0, i + 1);
			reverse(first.begin(), first.end());
			string middle = word.substr(i+1,j-i-1);
			reverse(middle.begin(), middle.end());
			string end = word.substr(j,word.length()-j+1);
			reverse(end.begin(), end.end());
			ans.push_back(first + middle + end);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << "\n";
	return 0;
}