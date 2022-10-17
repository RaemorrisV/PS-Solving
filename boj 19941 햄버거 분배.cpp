#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, k;
vector<char> table;
string input;
bool visited[20001];
int cnt = 0;
int main()
{
    cin >> n >> k >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'P')
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if (input[j] == 'H' && abs(i - j) <= k && visited[j] == false)
                {
                    visited[j] = true;
                    // cout<<i<<" "<<j<<endl;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}