#include <iostream>
#include <string>
using namespace std;

string input;
string N = "";
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> input;
	int check = 0;
	for (int i = 1; i < 25000; i++)
	{
		N += to_string(i);
		while (N.find(input[check]) != string::npos)
		{
			if (input.length() - 1 == check)
			{
				cout << i << '\n';
				exit(0);
			}
			N.erase(N.begin(), N.begin() + N.find(input[check]) + 1);
			check++;
		}
	}
	return 0;
}
