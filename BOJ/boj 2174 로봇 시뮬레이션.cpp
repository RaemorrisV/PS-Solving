#include <iostream>
#include <vector>

using namespace std;

struct robot {
	int row;
	int col;
	int dir;
};
struct order {
	int num;
	char oper;
	int iter;
};
vector<robot>robotorder;
vector<order>operation;
bool flag;
int land[101][101];
int dx[4] = { -1,0,1,0 }; //위 오 아 왼
int dy[4] = { 0,1,0,-1 };
int a, b, n, m; //열 행 개수 명령 개수
bool valide(int r, int c)
{
	if (r >= 1 && r <= b && c >= 1 && c <= a)return true;
	return false;
}
void simulation()
{
	for (int j = 0; j < m; j++)
	{
		int robotnum = operation[j].num;
		char o = operation[j].oper;
		int loop = operation[j].iter;
		for (int i = 1; i <= loop; i++)
		{
			if (o == 'L')
			{
				robotorder[robotnum - 1].dir = (robotorder[robotnum - 1].dir + 3) % 4;
			}
			else if (o == 'R')
			{
				robotorder[robotnum - 1].dir = (robotorder[robotnum - 1].dir + 1) % 4;
			}
			else if (o == 'F')
			{
				int nx = robotorder[robotnum - 1].row;
				int ny = robotorder[robotnum - 1].col;
				land[nx][ny] = 0;
				if (robotorder[robotnum - 1].dir == 0)
				{
					nx += dx[0] * i;
					if (valide(nx, ny) == false)
					{
						cout << "Robot " << robotnum << " crashes into the wall" << '\n';
						flag = true;
						return;
					}
					if (land[nx][ny] != 0)
					{
						cout << "Robot " << robotnum << " crashes into robot " << land[nx][ny] << '\n';
						flag = true;
						return;
					}
					if (i == loop) {
						land[nx][ny] = robotnum;
						robotorder[robotnum - 1].row = nx;
						robotorder[robotnum - 1].col = ny;
					}
				}
				else if (robotorder[robotnum - 1].dir == 1)
				{
					ny += dy[1] * i;
					if (valide(nx, ny) == false)
					{
						cout << "Robot " << robotnum << " crashes into the wall" << '\n';
						flag = true;
						return;
					}
					if (land[nx][ny] != 0)
					{
						cout << "Robot " << robotnum << " crashes into robot " << land[nx][ny] << '\n';
						flag = true;
						return;
					}
					if (i == loop) {
						land[nx][ny] = robotnum;
						robotorder[robotnum - 1].row = nx;
						robotorder[robotnum - 1].col = ny;
					}
				}
				else if (robotorder[robotnum - 1].dir == 2)
				{
					nx += dx[2] * i;
					if (valide(nx, ny) == false)
					{
						cout << "Robot " << robotnum << " crashes into the wall" << '\n';
						flag = true;
						return;
					}
					if (land[nx][ny] != 0)
					{
						cout << "Robot " << robotnum << " crashes into robot " << land[nx][ny] << '\n';
						flag = true;
						return;
					}
					if (i == loop) {
						land[nx][ny] = robotnum;
						robotorder[robotnum - 1].row = nx;
						robotorder[robotnum - 1].col = ny;
					}
				}
				else if (robotorder[robotnum - 1].dir == 3)
				{
					ny += dy[3] * i;
					if (valide(nx, ny) == false)
					{
						cout << "Robot " << robotnum << " crashes into the wall" << '\n';
						flag = true;
						return;
					}
					if (land[nx][ny] != 0)
					{
						cout << "Robot " << robotnum << " crashes into robot " << land[nx][ny] << '\n';
						flag = true;
						return;
					}
					if (i == loop) {
						land[nx][ny] = robotnum;
						robotorder[robotnum - 1].row = nx;
						robotorder[robotnum - 1].col = ny;
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int X, Y;
		char D;
		cin >> X >> Y >> D;
		if (D == 'N')
		{
			robotorder.push_back({ b + 1 - Y,X,0 });
		}
		else if (D == 'E')
		{
			robotorder.push_back({ b + 1 - Y,X,1 });
		}
		else if (D == 'S')
		{
			robotorder.push_back({ b + 1 - Y,X,2 });
		}
		else if (D == 'W')
		{
			robotorder.push_back({ b + 1 - Y,X,3 });
		}
		land[b + 1 - Y][X] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int X, Y;
		char D;
		cin >> X >> D >> Y;
		operation.push_back({ X,D,Y });
	}
	simulation();
	if (flag == false)cout << "OK" << '\n';
	return 0;
}