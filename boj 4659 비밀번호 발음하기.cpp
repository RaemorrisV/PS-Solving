#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, bool> vowel;
string input;
bool vowels()
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            return true;
    }
    return false;
}
bool cons()
{
    if (input.length() >= 3)
    {
        for (int i = 0; i <= input.length() - 3; i++)
        {
            if (vowel[input[i]] == vowel[input[i + 1]] && vowel[input[i + 1]] == vowel[input[i + 2]])
                return false;
        }
    }
    return true;
}
bool cons1()
{
    if (input.length() >= 2)
    {
        for (int i = 0; i <= input.length() - 2; i++)
        {
            string temp = "";
            if (input[i] == input[i + 1])
            {
                temp += input[i];
                temp += input[i + 1];
                if (temp == "ee" || temp == "oo")
                {
                    continue;
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vowel['a'] = true;
    vowel['e'] = true;
    vowel['i'] = true;
    vowel['o'] = true;
    vowel['u'] = true;
    while (1)
    {
        cin >> input;
        if (input == "end")
            break;
        if (vowels() && cons() && cons1())
        {
            cout << "<" << input << ">" << " "<<"is acceptable." << '\n';
        }
        else
        {
            cout << "<" << input << ">"<< " "<< "is not acceptable." << '\n';
        }
    }
    return 0;
}