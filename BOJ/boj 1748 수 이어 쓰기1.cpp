#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string n;
int first;
int N;
vector<int> arr;
int ans = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    N = stoi(n);
    int temp;
    for (int i = n.length() - 1; i >= 0; i--)
    {
        first = pow(10, i);
        temp=N-first;
        arr.push_back(temp + 1);
        N-=temp+1;
    }
    int k = 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans += arr[i] * k;
        k++;
    }
    cout << ans << '\n';
    return 0;
}