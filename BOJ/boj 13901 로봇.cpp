#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
int r, c,k;//행 열
bool room[1000][1000];
pair<int, int>robot;
queue<int>order;
int notmovecount = 0;
bool valid(int row, int col)
{
	if (row >= 0 && row < r && col >= 0 && col < c)return true;
	return false; 
}
bool simulation()
{
	int move=order.front();
	int nx = robot.first + dx[move];
	int ny = robot.second + dy[move];;
	//이래야만 들어갈 수 가 있음
	if (valid(nx, ny) && room[nx][ny] == false)
	{
		room[nx][ny] = true;
		robot.first = nx;
		robot.second = ny;
		notmovecount = 0;
	}
	else
	{
		order.pop();
		order.push(move);
		notmovecount++;
	}
	if (notmovecount == 4)return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> k; 
	for (int i = 0; i < k; i++)
	{
		int row, col;
		cin >> row >> col;
		room[row][col] = true;
	}
	int row, col;
	cin >> row >> col;
	room[row][col] = true;
	robot = { row,col };
	for (int i = 0; i < 4; i++)
	{
		int move;
		cin >> move;
		order.push(move-1);
	}
	while (simulation()){}
	cout << robot.first << " " << robot.second << '\n';
	return 0;
}