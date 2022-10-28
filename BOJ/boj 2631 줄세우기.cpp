#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int maxlength[201]; //i��° �ε������� ����� ���� ���� ����
vector<int>child(201);
int MAX = 0;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> child[i];
	}
	for (int i = 1; i <= n; i++)
	{
		maxlength[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (child[j] < child[i])
			{
				maxlength[i] = max(maxlength[j] + 1, maxlength[i]);
				MAX = max(maxlength[i], MAX);
			}
		}
	}
	cout << n - MAX << endl;
	return 0;
}