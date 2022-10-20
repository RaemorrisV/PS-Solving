#include <iostream>
#include <vector>
#include <string>
using namespace std;
string input;
int ans;
int cnt = 0;
vector<string> check = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int main()
{
    cin >> input;
    ans = input.length();
    for (int i = 0; i < check.size(); i++)
    {
        while (1)
        {
            if (input.find(check[i]) != string::npos)
            {
                input.replace(input.find(check[i]), check[i].length(), "4");
                //cout << input << endl;
                // ans += 1 - check[i].length();
            }
            else
            {
                break;
            }
        }
    }

    cout << input.length() << '\n';
    return 0;
}