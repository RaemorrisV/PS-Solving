#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, S, sum = 0;
vector<int> arr;
vector<int> ans;
int MIN = 100000001;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> S;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int s = 0;
    int e = 0;
    sum = arr[s];
    ans.push_back(arr[s]);
    while (1)
    {
        if (e == n && sum < S)
        {
            break;
        }
        if (sum < S)
        {
            e++;
            ans.push_back(1);
            sum += arr[e];
        }
        else if (sum >= S) //ㅇㅇ
        {
            int siz = ans.size();
            MIN = min(MIN, siz);
            ans.pop_back();
            sum -= arr[s];
            s++;
        }
    }
    if (MIN == 100000001)
    {
        cout << "0" << '\n';
    }
    else
    {
        cout << MIN << '\n';
    }
    return 0;
}