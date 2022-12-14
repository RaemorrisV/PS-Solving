#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
string in;
int MAX = INT_MIN;
int calculate(int a, int b, char op)
{
    int v = a;
    if (op == '+')
    {
        v += b;
    }
    else if (op == '-')
    {
        v -= b;
    }
    else
    {
        v *= b;
    }
    return v;
}
void dfs(int idx, int total)
{
    if (idx > n - 1)
    {
        MAX = max(MAX, total);
        return;
    }
    char oper = (idx == 0) ? '+' : in[idx - 1];
    //괄호로 묶었을 경우
    if (idx + 2 < n)
    {
        int bracket_value = calculate(in[idx] - '0', in[idx + 2] - '0', in[idx + 1]);
        dfs(idx + 4, calculate(total, bracket_value, oper));
    }
    //괄호x
    dfs(idx + 2, calculate(total, in[idx] - '0', oper));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    cin >> in;
    dfs(0, 0);
    cout << MAX << '\n';
    return 0;
}