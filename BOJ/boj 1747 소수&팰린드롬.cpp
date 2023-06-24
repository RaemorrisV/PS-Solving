#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int n;
bool prime[2000001];
void prime_check() {
	for (int i = 2; i <= sqrt(2000000); i++)
	{
		if (prime[i])
		{
			for (int j = i * 2; j <= 2000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
}
bool palindrome(string word)
{
	string temp = word;
	reverse(word.begin(), word.end());
	if(temp == word)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	fill(prime + 1, prime + 2000002, true);
	//소수 판별후
	prime_check();
	prime[1] = false;
	for (int i = n; i <= 2000002; i++)
	{
		if (prime[i] && palindrome(to_string(i)))
		{
			cout << i << '\n';
			break;
		}
		else continue;
	}

	return 0;
}