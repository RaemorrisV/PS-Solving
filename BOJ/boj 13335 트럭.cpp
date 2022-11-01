#include <iostream>
#include <vector>
using namespace std;

int n, w, l;
int t = 0;
int cnt = 0;
int sum = 0;
bool flag = false;
vector<int> truck;
vector<pair<int, int>> bridge; //현재위치와 트럭 번호
void passing()
{
    while (1)
    {
        if (bridge.size() == 0)
        {
            break;
        }
        else
        {
            t++;
            for (int i = 0; i < bridge.size(); i++)
            {
                bridge[i].first += 1;
                if (bridge[i].first > w)
                {
                    sum -= truck[bridge[i].second];
                    flag = true;
                }
            }
            if (flag)
            {
                flag = false;
                bridge.erase(bridge.begin());
            }
            if (sum + truck[cnt] <= l)
            {
                if (cnt < n)
                {
                    sum += truck[cnt];
                    bridge.push_back({1, cnt++});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        truck.push_back(input);
    }
    sum += truck[cnt];
    bridge.push_back({1, cnt++});
    t++;
    passing();
    cout << t << '\n';
    return 0;
}