#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alphabet[26];
int even[26];//¦������ �ƴ��� �Ǻ�
int oddcnt = 0; //0�̰ų� 1�̿��� �Ӹ������ �������������
string name;
string ans = "";
string middle="";
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> name;
	for (int i = 0; i < name.length(); i++)
	{
		alphabet[name[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		//Ȧ����
		if (alphabet[i] % 2 == 1)oddcnt++;
	}
	if (oddcnt >= 2)cout << "I'm Sorry Hansoo" << '\n';
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] % 2 == 0)//¦���϶�
			{
				for (int j = 0; j < alphabet[i]/2; j++)
				{
					ans += char(i+'A');
				}
				alphabet[i] -= (alphabet[i] / 2);
			}
			else if (alphabet[i] % 2 == 1)//Ȧ���ϋ�
			{
				middle += char(i + 'A');;
				for (int j = 0; j < (alphabet[i]-1) / 2; j++)
				{
					ans += char(i + 'A');
				}
				alphabet[i] -= ((alphabet[i]-1) / 2);
			}
		}
		string temp = ans;
		temp += middle;
		reverse(ans.begin(), ans.end());
		temp += ans;
		cout << temp << '\n';
	}
	return 0;
}
