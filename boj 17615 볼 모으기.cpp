#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
vector<char> ball;
int n;
string input;
int cnt = 0;
int MIN = INT_MAX;
int main()
{
    cin >> n >> input;
    for (int i = 0; i < n; i++)
    {
        ball.push_back(input[i]);
    }
    //먼저 빨간공부터 옮겨보도록 하자
    vector<char> temp = ball;
    for (int i = n - 1; i >= 0; i--) //오른쪽으로 옮기기
    {
        if (i != n - 1 && temp[i] == 'R' && temp[i + 1] == 'B') //뛰어 넘어 옮길수 있음
        {
            cnt++;
            temp[i] = 'B';
        }
    }
    //cout << cnt << endl;
    MIN = min(MIN, cnt);
    cnt = 0;
    temp = ball;
    for (int i = 0; i < n; i++) //왼쪽으로
    {
        if (i != 0 && temp[i] == 'R' && temp[i - 1] == 'B') //뛰어 넘어 옮길수 있음
        {
            cnt++;
            temp[i] = 'B';
        }
    }
    MIN = min(MIN, cnt);
    cnt = 0;
    temp = ball;
    for (int i = 0; i < n; i++) //왼쪽으로
    {
        if (i != 0 && temp[i] == 'B' && temp[i - 1] == 'R') //뛰어 넘어 옮길수 있음
        {
            cnt++;
            temp[i] = 'R';
        }
    }
    MIN = min(MIN, cnt);
    cnt = 0;
    temp = ball;
    for (int i = n - 1; i >= 0; i--) //오른쪽으로 옮기기
    {
        if (i != n - 1 && temp[i] == 'B' && temp[i + 1] == 'R') //뛰어 넘어 옮길수 있음
        {
            // cout << "출력 " << i << endl;
            cnt++;
            temp[i] = 'R';
        }
    }
    MIN = min(MIN, cnt);
    cout << MIN << endl;
    return 0;
}