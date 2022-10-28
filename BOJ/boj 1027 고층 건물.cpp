#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> building(51); //높이가 들어있음
int n;
int cnt = 0;
double gradient1, gradient2;
int MAX = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> building[i];
    }
    for (int i = 1; i <= n; i++) // i를 기준으로 j 번째 빌딩이 보이나
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                gradient1 = ((double)(building[i] - building[j]) / (i - j)); //기울기
                if (i < j)
                {
                    bool check = true;
                    for (int z = i + 1; z < j; z++)
                    {
                        gradient2 = ((double)(building[i] - building[z]) / (i - z));
                        if (gradient1 <= gradient2)
                        {
                            check = false;
                            break;
                        }
                    }
                    if (check == true)
                        cnt++;
                }
                if (i > j)
                {
                    bool check = true;
                    for (int z = j + 1; z < i; z++)
                    {
                        gradient2 = ((double)(building[z] - building[i]) / (z - i));
                        if (gradient1 >= gradient2)
                        {
                            check = false;
                            break;
                        }
                    }
                    if (check == true)
                        cnt++;
                }
            }
        }
        MAX = max(MAX, cnt);
        cnt = 0;
    }
    cout << MAX << endl;
    return 0;
}