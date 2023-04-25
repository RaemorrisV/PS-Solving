#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<string>

using namespace std;

unordered_map<string, double>map;

double sum = 0;
double total = 0;
double ans;
int main()
{
	map["A+"] = 4.5;
	map["A0"] = 4.0;
	map["B+"] = 3.5;
	map["B0"] = 3.0;
	map["C+"] = 2.5;
	map["C0"] = 2.0;
	map["D+"] = 1.5;
	map["D0"] = 1.0;
	map["F"] = 0.0;

	while (1) {
		string inp;
		getline(cin, inp);
		if (inp == "")break;

		stringstream ss(inp);
		vector<string> result;
		string str;
		while (ss >> str) {
			result.push_back(str);
		}
		if (result[2] != "P")
		{
			sum += stod(result[1]);
			total += (map[result[2]] * stod(result[1]));
		}
	}
	cout.precision(7);
	cout << total / sum << '\n';
	return 0;
}