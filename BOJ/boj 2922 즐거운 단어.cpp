#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool visited[26];
unordered_map<char, bool>vowel;
string word;
vector<int>underbar;
long long ans;
bool isNext(int index, int alphabet)
{
	index = underbar[index];
	if (alphabet == 2)alphabet = 11;
	int temp = 0;
	int temp1 = 0;
	if (vowel[alphabet + 'A'])temp++;
	else temp1++;
	if (index - 2 >= 0)
	{
		int v = temp;
		int nv = temp1;
		for (int i = index - 2; i <= index; i++)
		{
			if (vowel[word[i]])v++;
			else if (word[i] != '_')nv++;
		}
		if (v == 3 || nv == 3)return false;
	}
	if (index - 1 >= 0 && index + 1 <= word.length() - 1)
	{
		int v = temp;
		int nv = temp1;
		for (int i = index - 1; i <= index + 1; i++)
		{
			if (vowel[word[i]])v++;
			else if (word[i] != '_')nv++;
		}
		if (v == 3 || nv == 3)return false;
	}
	if (index + 2 <= word.length() - 1)
	{
		int v = temp;
		int nv = temp1;
		for (int i = index; i <= index + 2; i++)
		{
			if (vowel[word[i]])v++;
			else if (word[i] != '_')nv++;
		}
		if (v == 3 || nv == 3)return false;
	}
	return true;
}
void dfs(int index, int depth, bool isL, int v, int nv)
{
	if (depth == underbar.size() && isL)
	{
		ans += (long long)pow(5 , v) * (long long)pow(20,nv);
		return;
	}
	if (depth == underbar.size())return;
	for (int i = 0; i < 3; i++) //0 모음 1 자음 2 L
	{
		if (isNext(index, i))
		{
			if (i == 2)word[underbar[index]] = 11 + 'A';
			else word[underbar[index]] = i + 'A';
			if (i == 0)dfs(index + 1, depth + 1, isL, v + 1, nv);
			if (i == 1)dfs(index + 1, depth + 1, isL, v, nv + 1);
			if (i == 2)dfs(index + 1, depth + 1, true, v, nv );
			word[underbar[index]] = '_';
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> word;
	vowel['A'] = true;
	vowel['E'] = true;
	vowel['I'] = true;
	vowel['O'] = true;
	vowel['U'] = true;
	bool flag = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '_')
		{
			underbar.push_back(i);
		}
		if (word[i] == 'L')flag = true;
	}
	dfs(0, 0, flag, 0, 0);
	cout << ans << '\n';
	return 0;
}
