#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int MAX = -1;
vector<string> words;
vector<char> usealpha;
int alpha[26];
bool visited[10];
vector<int> permutation;
vector<int> total = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void calculate()
{
    int temp = 0;
    int sum = 0;
    for (int i = 0; i < usealpha.size(); i++)
    {
        alpha[usealpha[i] - 'A'] = permutation[i];
    }
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            temp *= 10;
            temp += alpha[words[i][j] - 'A'];
        }
        sum += temp;
        temp = 0;
    }
    MAX = max(MAX, sum);
}
void dfs(int s)
{
    permutation.push_back(total[s]);
    if (permutation.size() == usealpha.size())
    {
        calculate();
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
            permutation.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fill(alpha, alpha + 26, -1);
    words.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        for (int j = 0; j < words[i].length(); j++)
        {
            if (alpha[words[i][j] - 'A'] == -1)
            {
                alpha[words[i][j] - 'A'] = 1;
                usealpha.push_back(words[i][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        visited[i] = true;
        dfs(i);
        permutation.pop_back();
        visited[i] = false;
    }
    cout << MAX << '\n';
    return 0;
}