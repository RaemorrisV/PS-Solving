#include <iostream>
#include <string>

using namespace std;
int num;
int main()
{
    cin >> num;
    for (int i = 1; i <= 1000; i++)
    {
        if (2 * i - 1 == num)
        {
            cout << "SK" << endl;
        }
        else if (2 * i == num)
        {
            cout << "CY" << endl;
        }
    }
    return 0;
}