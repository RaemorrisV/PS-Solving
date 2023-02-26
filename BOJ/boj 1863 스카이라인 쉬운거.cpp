#include <iostream>
#include <stack>

using namespace std;
int n, ans;
stack<int>height;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	height.push(0);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (height.top() < b)
		{
			ans++;
			height.push(b);
		}
		else if(height.top() > b)
		{
			while (1)
			{
				height.pop();
				if (height.top() == b)
				{
					break;
				}
				else if (height.top() < b)
				{
					ans++;
					height.push(b);
					break;
				}
				else if (height.top() == 0)
				{
					break;
				}
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}