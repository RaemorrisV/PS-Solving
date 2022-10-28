#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, input;
vector<int> stock;
long long revenue = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //주식을 하나 사거나 팔거나 아무것도 안함
    //앞에서 부터 구현을 시작하니 매우어려움 뒤에서 부터 시작하도록 하자
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            stock.push_back(input);
        }
        int MAX = stock[n - 1];
        for (int j = n - 2; j >= 0; j--) //아무래도 팔때 갱신하는게 맞겠지
        {
            MAX = max(MAX, stock[j]);
            if (MAX != stock[j])
            {
                revenue += (long long)(MAX - stock[j]);
            }
        }
        cout << revenue << '\n';
        revenue = 0;
        stock.clear();
    }
    return 0;
}