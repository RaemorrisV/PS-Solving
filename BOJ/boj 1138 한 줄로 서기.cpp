#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>arr(10);
vector<int>temp(10); //순서 저장
vector<int>ans(10);
vector<int>arr1(10);
int n;
void dfs(int tall)
{
	if (tall == n)//이경우
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)// temp 의 원소는 
		{
			for (int j = 0; j < i; j++)
			{
				if (temp[i] < temp[j])
				{
					cnt++;
				}
			}
			arr1[temp[i]] = cnt;
			cnt = 0;
		}
		if (arr == arr1)
		{
			ans = temp;
		}
		return;
	}
	//아닐 경우
	for (int i = 0; i < n; i++)
	{
		if (temp[i] == -1)
		{
			temp[i] = tall;
			dfs(tall + 1);
			temp[i] = -1;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	fill(temp.begin(), temp.end(), -1);
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}