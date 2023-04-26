#include <iostream>

using namespace std;

int c, r, k;//열 행 몇 번째
int current_order = 1;
int arr[8][8];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> c >> r >> k;
	int R = 1;
	int C = 1;
	bool flag = false;
	if (c * r < k)
	{
		cout << 0 << '\n';
	}
	else
	{
		int check = 1;
		while (1)
		{
			if (current_order == k) {
				flag = true;
				break;
			}
			r--;
			c--;
			for (int i = 1; i <= r; i++)
			{
				if (check % 2 == 1)R += 1;
				else if (check % 2 == 0)R -= 1;
				current_order += 1;
				if (current_order == k) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			if (check % 2 == 1)C += 1;
			else if (check % 2 == 0)C -= 1;
			current_order += 1;
			if (current_order == k) {
				flag = true;
				break;
			}
			for (int i = 1; i <= c-1; i++)
			{
				if (check % 2 == 1)C += 1;
				else if (check % 2 == 0)C -= 1;
				current_order += 1;
				if (current_order == k) {
					flag = true;
					break;
				}
			}
			if (flag)break;
			if (check % 2 == 1)R -= 1;
			else if (check % 2 == 0)R += 1;
			current_order += 1;
			if (current_order == k) {
				flag = true;
				break;
			}
			check++;
		}
		cout << C << " " << R << '\n';
	}
	return 0;
}