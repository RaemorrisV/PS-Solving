#include<iostream>
#include<queue>
using namespace std;

int n;
queue<int>card;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		card.push(i);
	}
	while (card.size() != 1)
	{
		card.pop();
		int second = card.front();
		card.pop();
		card.push(second);
	}
	cout << card.front() << endl;
	return 0;
}