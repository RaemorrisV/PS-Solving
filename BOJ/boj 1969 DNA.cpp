#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> DNA;
int n, m;
string result = "";
int ans;
int alphabet[26];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		DNA.push_back(word);
	}
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			alphabet[DNA[j][i] - 'A']++;
		}
		int MAX = 0;
		char a;
		for (int j = 0; j < 26; j++)
		{
			if (MAX < alphabet[j])
			{
				MAX = alphabet[j];
				a = j + 'A';
			}
		}
		result += a;
		ans += n - MAX;
		memset(alphabet, 0, sizeof(alphabet));
	}
	cout << result << '\n';
	cout << ans << "\n";
	return 0;
}