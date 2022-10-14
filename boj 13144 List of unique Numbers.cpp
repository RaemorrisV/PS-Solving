#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//전체 갯수에서 빼보도록 짜보자 투포인터를 이용하여
vector<int> arr;
unordered_map<int, int> check;
int n;
long long cnt;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    cnt = (arr.size() * (arr.size() + 1)) / 2;
    int s = 0;
    int e = 1;
    check[arr[s]] = 1; //초기 값 설정
    while (e < n)
    {
        if (check.find(arr[e])!=check.end()) //있다면
        {
            check.erase(arr[s]);
            s++;
            cnt-=n-e;
        }
        else 
        {
            check[arr[e]]=1;
            e++;
        }
    }
    cout << cnt << endl;
    return 0;
}