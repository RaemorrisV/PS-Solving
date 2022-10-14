#include <iostream>
#include <vector>
using namespace std;
vector<int> block;
int r, c, a;
int cnt = 0;
int main()
{
    cin >> r >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a;
        block.push_back(a);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j < block.size(); j++)
        {
            if (block[j] < i)//빗물이 들어갈 곳
            {
                int s = j;
                int e = j;
                while (1)
                {
                    if (s<0 || e> block.size() - 1)
                    {
                        s = j;
                        e = j + 1;
                        break;
                    }
                    if (block[s] >= i && block[e] >= i)
                    {
                        j = e;
                        break;
                    }
                    if (block[s] < i)
                    {
                        s--;
                    }
                    if (block[e] < i)
                    {
                        e++;
                    }
                }
                cnt += e - s - 1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}