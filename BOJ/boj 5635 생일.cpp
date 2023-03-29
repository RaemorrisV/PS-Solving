#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
struct info {
	string name;
	int day;
	int month;
	int year;
};
vector<info>student;
bool compare(info a, info b)
{
	if (a.year == b.year)
	{
		if (a.month == b.month)
		{
			return a.day < b.day;
		}
		else return a.month < b.month;
	}
	else return a.year < b.year;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		int a, b, c;
		cin >> input >> a >> b >> c;
		student.push_back({ input,a,b,c });
	}
	sort(student.begin(), student.end(), compare);
	/*
	for (int i = 0; i < n; i++)
	{
		cout << student[i].year << " " << student[i].month << " " << student[i].day << endl;
	}
	*/
	cout << student[n - 1].name << '\n';
	cout << student[0].name << '\n';
	return 0;
}