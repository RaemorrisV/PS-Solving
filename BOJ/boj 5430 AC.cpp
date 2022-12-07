#include <iostream>
#include <string>
#include <deque>
using namespace std;

int t, n;
string p;
string input;
bool error;
deque<string> dq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> p;
        cin >> n;
        cin >> input;
        if (n != 0)
        {
            string temp = "";
            for (int j = 1; j < input.length(); j++)
            {
                if (input[j] == ',' || input[j] == ']')
                {
                    dq.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += input[j];
                }
            }
            int dir = 1; // 1 이면 정방향 -1이면 리버스
            for (int j = 0; j < p.length(); j++)
            {
                if (dq.empty() && p[j] == 'D')
                {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                else if (p[j] == 'D')
                {
                    if (dir == 1)
                    {
                        dq.pop_front();
                    }
                    else if (dir == -1)
                    {
                        dq.pop_back();
                    }
                }
                else if (p[j] == 'R')
                {
                    dir = -dir;
                }
            }
            if (!error)
            {
                if (dir == 1)
                {
                    cout << '[';
                    while (!dq.empty())
                    {
                        if (dq.size() != 1)
                        {
                            cout << dq.front() << ',';
                            dq.pop_front();
                        }
                        else if (dq.size() == 1)
                        {
                            cout << dq.front();
                            dq.pop_front();
                        }
                    }
                    cout << ']';
                    cout << '\n';
                }
                else
                {
                    cout << '[';
                    while (!dq.empty())
                    {
                        if (dq.size() != 1)
                        {
                            cout << dq.back() << ',';
                            dq.pop_back();
                        }
                        else if (dq.size() == 1)
                        {
                            cout << dq.back();
                            dq.pop_back();
                        }
                    }
                    cout << ']';
                    cout << '\n';
                }
            }
            error = false;
        }
        else if (n == 0)
        {
            for (int j = 0; j < p.length(); j++)
            {
                if (p[j] == 'D')
                {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
            }
            if (!error)
            {
                cout << "[]" << '\n';
            }
            error = false;
        }
    }
    return 0;
}