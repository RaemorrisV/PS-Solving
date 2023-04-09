#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
bool prime[10001];
unordered_map<string, bool>check;
int p, n, m;
void find_prime()
{
	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (prime[i])
		{
			for (int j = i * 2; j <= 10000; j += i)
			{
				prime[j] = false;
			}
		}
	}
}
bool simulation(int num)
{
	check.clear();
	string temp = to_string(num);
	check[temp] = true;
	bool flag = false;
	while (1)
	{
		int val = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			val += pow(temp[i] - '0', 2);
		}
		temp = to_string(val);
				if (temp == "1")
		{
			flag = true;
			break;
		}
		if (check[temp])
		{
			flag = false;
			break;
		}
		check[temp] = true;
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> p;
	fill(prime, prime + 10001, 1);
	prime[1] = false;
	find_prime();
	for (int tc = 1; tc <= p; tc++)
	{
		cin >> n >> m;
		if (prime[m] == false)cout << tc << " " << m << " " << "NO" << '\n';
		else
		{
			if (simulation(m))
			{
				cout << tc << " " << m << " " << "YES" << '\n';
			}
			else
			{
				cout << tc << " " << m << " " << "NO" << '\n';
			}
		}
	}
	return 0;
}