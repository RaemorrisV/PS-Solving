#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int n, m;
unordered_set<string>keywords;//���� �Ⱦ������ٴ� �ǹ�
string input;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		keywords.insert(input);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		auto it = input.find(",");
		while (it != string::npos)//�ִٸ� ��� �ݺ��մϴ�
		{
			string temp = input.substr(0, it);
			input.erase(input.begin(), input.begin() + it + 1);
			if (keywords.find(temp) != keywords.end())
			{
				keywords.erase(temp);
			}
			it = input.find(",");
		}
		string temp1 = input;
		if (keywords.find(temp1) != keywords.end())
		{
			keywords.erase(temp1);
		}
		cout << keywords.size() << '\n';
	}
	return 0;
}