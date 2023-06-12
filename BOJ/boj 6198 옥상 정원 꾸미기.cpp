#include <iostream>
#include <stack>
#include <vector>
using namespace std;
long long n, result;
stack<int> st;
vector<int>arr;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top() <= arr[i])st.pop();
		result += st.size();
		st.push(arr[i]);
	}
	cout << result << '\n';
	return 0;
}