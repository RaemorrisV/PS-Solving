#include <iostream>
#include <vector>
using namespace std;
vector<int> student;
int p, n, input;
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> n;
        for (int j = 0; j < 20; j++)
        {
            cin >> input;
            if (j == 0)
            {
                student.push_back(input);
            }
            else
            {
                if (student.back() < input)
                {
                    student.push_back(input);
                }
                else
                {
                    for (int k = 0; k < 20; k++)
                    {
                        if (student[k] > input)
                        {
                            student.insert(student.begin() + k, input);
                            cnt += j - k;
                            break;
                        }
                    }
                }
            }
        }
        cout << n << " " << cnt << '\n';
        cnt = 0;
        /*
        for (int j = 0; j < 20; j++)
        {
            cout << student[j] << " ";
        }
        cout << endl;
        */
        student.clear();
    }
    return 0;
}