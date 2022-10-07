#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std; // 0->A부터 시작 //대문자로 저장하는 것으로 하자
char find_f;
unordered_map<char, int> alpabet;
bool compare(pair<char, int> a, pair<char, int> b)
{
    return a.second < b.second;
}
int main()
{
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        find_f = input[i];
        if (find_f < 97) //대문자
        {
            if (alpabet.find(find_f) != alpabet.end()) //있으면
            {
                alpabet[find_f]++;
            }
            else
            {
                alpabet[find_f] = 1;
            }
        }
        else if (find_f >= 97) //소문자
        {
            char s = find_f - 32;
            if (alpabet.find(s) != alpabet.end()) //있으면
            {
                alpabet[s]++;
            }
            else
            {
                alpabet[s] = 1;
            }
        }
    }
    vector<pair<char, int>> ans(alpabet.begin(), alpabet.end());
    sort(ans.begin(), ans.end(), compare);
    if (ans[ans.size() - 1].second == ans[ans.size() - 2].second)
    {
        cout << "?" << endl;
    }
    else
    {
        cout << ans[ans.size() - 1].first << endl;
    }
    return 0;
}