#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

stack<pair<char, bool>>st;

string input;
vector<string>ans;
int cnt = 0;
bool use[13];
unordered_map<string, bool>duplicate;

void dfs(int idx,int num)
{
	//���������� ����?
	if (cnt == num)
	{
		int check = 0;
		string out = "";
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(')
			{
				check++;
				if (use[check])
				{
					out += '(';
					st.push({ '(', true });
				}
				else
				{
					st.push({ '(', false });
				}
			}
			else if (input[i] == ')')
			{
				if (st.top().second)//true ���
				{
					out += ')';
					st.pop();
				}
				else
				{
					st.pop();
				}
			}
			else
			{
				out += input[i];
			}
		}
		if (duplicate[out] == false)
		{
			duplicate[out] = true;
			ans.push_back(out);
		}
		return;
	}
	for (int i = idx+1; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			//���� ����
			use[num+1] = true;
			dfs(i, num+1);
			//���� ��
			use[num+1] = false;
			dfs(i, num+1);
			use[num+1] = false;
		    break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	duplicate[input] = true;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')cnt++; //�� ���ִ��� üũ ���� ���ְ�
	}
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			//���� ����
			use[1] = true;
			dfs(i,1);
			//���� ��
			use[1] = false;
			dfs(i,1);
			use[1] = false;
			break;
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}