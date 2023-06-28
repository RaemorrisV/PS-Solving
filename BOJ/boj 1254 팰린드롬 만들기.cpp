#include <iostream>
#include <algorithm>

using namespace std;

string s;
int ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	string temp = "";
	for (int i = s.length()-1; i >= 0; i--)
	{
		temp = s[i] + temp;
		string compar = temp;
		reverse(temp.begin(), temp.end());
		if (compar == temp)ans = temp.length();
		reverse(temp.begin(), temp.end());
	}
	cout << s.length() + (s.length() - ans) << '\n';
	return 0;
}