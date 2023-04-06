#include <iostream>
#include <vector>

using namespace std;

struct light {
	int idx;
	int R;
	int G;
};
vector<light>trafficlight;//R G순으로 
int n, l, ans, d, r, g;
void simulation()
{
	for (int i = 0; i < trafficlight.size(); i++)
	{
		if (i == 0)ans += trafficlight[0].idx;
		else
		{
			ans += trafficlight[i].idx - trafficlight[i - 1].idx;
		}
		//g를 생각을 안해줬네
		int mod = ans % (trafficlight[i].R + trafficlight[i].G);
		if (mod <= trafficlight[i].R)ans += trafficlight[i].R - mod;
	}
	ans += l - trafficlight[n - 1].idx;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> d >> r >> g;
		trafficlight.push_back({ d,r,g });
	}
	simulation();
	cout << ans << '\n';
	return 0;
}