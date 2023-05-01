#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int>grade;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			grade.push_back(a);
		}
		sort(grade.begin(), grade.end());
		int diff = 0;
		for (int i = 0; i < n - 1; i++)
		{
			diff = max(diff, grade[i + 1] - grade[i]);
		}
		cout << "Class " << tc << '\n';
		cout << "Max " << grade[grade.size() - 1] << ", " << "Min " << grade[0] << ", " << "Largest gap " << diff << '\n';
		grade.clear();
	}
	return 0;
}