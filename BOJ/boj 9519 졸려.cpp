#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int x;
int MOD;
string word;
unordered_map<string, bool>duplicated;
vector<string>arr;
void simulation()
{
	string temp = "";
	string end = "";
	for (int i = 0; i < word.length(); i++)
	{
		if (i % 2 == 1)
		{
			end += word[i];
		}
		else temp += word[i];
	}
	reverse(end.begin(), end.end());
	word = temp + end;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> x >> word;
	while (duplicated[word]==false)
	{
		duplicated[word] = true;
		arr.push_back(word);
		simulation();
		MOD++;
	}
	cout << arr[x%MOD] << '\n';
	return 0;
}