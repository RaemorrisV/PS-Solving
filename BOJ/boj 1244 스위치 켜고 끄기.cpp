#include <iostream>
#include <vector>

using namespace std;
vector<int> Switch(101);
int n, student_num;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> Switch[i];
    }
    cin >> student_num;
    for (int i = 0; i < student_num; i++)
    {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1) //남학생의 경우
        {
            for (int j = num; j <= n; j++)
            {
                if (j % num == 0)
                {
                    if (Switch[j] == 1)
                    {
                        Switch[j] = 0;
                    }
                    else
                    {
                        Switch[j] = 1;
                    }
                }
            }
        }
        else //여학생의 경우
        {
            int s = num;
            int e = num;
            while (1)
            {
                if (Switch[s] == Switch[e])
                {
                    //cout<<s<<" "<<e<<endl;
                    if(s==1||e==n)break;
                    s--;
                    e++;
                }
                else
                {
                    s++;e--;
                    break;
                }
            }
          //s++;e--;
            for (int j = s; j <= e; j++)
            {
                if (Switch[j] == 1)
                {
                    Switch[j] = 0;
                }
                else
                {
                    Switch[j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << Switch[i] <<" ";
        if (i % 20 == 0)
        {
            cout << '\n';
        }
    }
    cout << '\n';
    return 0;
}