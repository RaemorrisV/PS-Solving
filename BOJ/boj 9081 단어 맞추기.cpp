#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int t;
vector<string>st;
string simulation(string word)
{
	for (int i = word.length() - 2; i >= 0; i--)
	{
		for (int k = word.length()-1; k >= i+1; k--)
		{
			if (word[i] < word[k]) //¹Ù²¸¾ßµÊ
			{
				char temp = word[i];
				word[i] = word[k];
				word[k] = temp;
				string first = "";
				string second = "";
				for (int j = 0; j <= i; j++)
				{
					first += word[j];
				}
				//cout << "first " << first << endl;
				for (int j = i+1; j < word.length(); j++)
				{
					second += word[j];
				}
				//cout << "second " << second << endl;
				sort(second.begin(), second.end());
				return first + second;
			}
		}
	}
	return word;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		string input;
		cin >> input;
		cout << simulation(input) << '\n';

	}
	return 0;
}