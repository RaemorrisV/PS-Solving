#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0;
	while (1)
	{		
		if (n <= 0)
		{
			break;
		}
		else
		{
			n -= i;
			i++;
		}
	}
	i-=1;
	if(i%2==0)//짝수줄 라인에 있을때
	{
		cout << i + n << "/" <<1 - n <<endl;
	}
	else //홀수줄 라인에 있을때
	{
		cout<<1 - n<<"/"<< i + n <<endl;
	}
	return 0;
}