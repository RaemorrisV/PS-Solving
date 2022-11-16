#include <iostream>

using namespace std;

int n;
long long x;
long long bur[51];   //버거의 전체 재료의 갯수
long long patty[51]; //패티의 갯수
long long dfs(int len, long long ate)
{
     if(len==0)
     {
        if(ate==1)return 1;
        else if(ate==0)return 0;
     }
     if(ate==1)return 0;
     else if(ate<=bur[len-1]+1)return dfs(len-1,ate-1);
     else if(ate==bur[len-1]+2)return patty[len-1]+1;
     else if(ate<=2*bur[len-1]+2)return dfs(len-1,ate-bur[len-1]-2)+1+patty[len-1];
     else 
     {
        return patty[len-1]*2+1;
     }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x;
    patty[0] = 1;
    bur[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bur[i] = 2 * bur[i - 1] + 3;
        patty[i] = 2 * patty[i - 1] + 1;
    }
    cout << dfs(n,x) << '\n';
    return 0;
}