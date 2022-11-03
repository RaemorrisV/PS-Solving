#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> house; //중앙에 있는게 최적해 인듯
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        house.push_back(input);
    }
    sort(house.begin(), house.end());
    if (n % 2 == 1) //홀수라면
    {
        cout << house[floor(n / 2)] << "\n";
    }
    else //짝수라면
    {
        cout << house[n / 2 - 1] << "\n";
    }
    return 0;
}