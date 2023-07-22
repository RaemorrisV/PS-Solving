#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
int cost[101];
int weight[2001];
int parkinglot[101];
int ans;
queue<int>waiting;
int isPossible()
{
	for (int i = 1; i <= n; i++)
	{
		if (parkinglot[i] == 0)return i;
	}
	return -1;
}
int findCar(int num)
{
	for (int i = 1; i <= n; i++)
	{
		if (parkinglot[i] == num)return i;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> weight[i];
	}
	int car;
	for (int i = 0; i < 2 * m; i++)
	{
		cin >> car;
		if (car < 0) //음수면 나가는 차
		{
			int space = findCar(abs(car));
			parkinglot[space] = 0;
			ans += cost[space] * weight[abs(car)];
			if (!waiting.empty())
			{
				int first = waiting.front();
				waiting.pop();
				int index = isPossible();
				parkinglot[index] = first;
			}
		}
		else // 들오오면
		{
			//주차장이 비어있는지 확인
			int parking = isPossible();
			if (parking == -1)//자리없음
			{
				waiting.push(car);
			}
			else //자리가 있으면 
			{
				parkinglot[parking] = car;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}