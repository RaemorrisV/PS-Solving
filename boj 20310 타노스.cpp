#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
vector<int> idx_1;
int one_cnt = 0;
int zero_cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '1')
        {
            one_cnt++;
            idx_1.push_back(i);
        }
        else
        {
            zero_cnt++;
        }
    }
    for (int i = 0; i < idx_1.size() / 2; i++)
    {
        input.erase(input.begin() + idx_1[i] - i);
    }
    int cnt = 0;
    // cout<<input<<endl;
    for (int i = input.length() - 1; i >= 0; i--)
    {
        if (cnt < zero_cnt / 2 && input[i] == '0')
        {
            input.erase(i, 1);
            cnt++;
        }
    }
    cout << input << '\n';
    return 0;
}