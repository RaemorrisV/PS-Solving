#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
bool compare(tuple<int,string,int>&v1,tuple<int,string,int>&v2)
{
	if (get<0>(v1) == get<0>(v2))
	{
		return get<2>(v1) < get<2>(v2);
	}
	else
	{
		return get<0>(v1) < get<0>(v2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n; 
	vector<tuple<int, string,int>> information;//나이 이름 들어온 순서
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		information.push_back(make_tuple(age, name, i));
	}
	sort(information.begin(), information.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << get<0>(information[i]) << " " << get<1>(information[i]) << "\n";
	}
	return 0;
}