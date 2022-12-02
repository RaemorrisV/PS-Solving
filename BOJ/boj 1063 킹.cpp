#include <iostream>
#include <string>
using namespace std;

string king, rock;
int n;
bool valide(char r, char c)
{
    if (r >= '1' && r <= '8' && c >= 'A' && c <= 'H')
        return true;
    return false;
}
void simulation(string c)
{
    if (c == "R")
    {
        char nx = king[1];
        char ny = king[0] + 1;
        char r_nx = rock[1];
        char r_ny = rock[0] + 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "L")
    {
        char nx = king[1];
        char ny = king[0] - 1;
        char r_nx = rock[1];
        char r_ny = rock[0] - 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "B")
    {
        char nx = king[1] - 1;
        char ny = king[0];
        char r_nx = rock[1] - 1;
        char r_ny = rock[0];
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "T")
    {
        char nx = king[1] + 1;
        char ny = king[0];
        char r_nx = rock[1] + 1;
        char r_ny = rock[0];
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "RT")
    {
        char nx = king[1] + 1;
        char ny = king[0] + 1;
        char r_nx = rock[1] + 1;
        char r_ny = rock[0] + 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "LT")
    {
        char nx = king[1] + 1;
        char ny = king[0] - 1;
        char r_nx = rock[1] + 1;
        char r_ny = rock[0] - 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "RB")
    {
        char nx = king[1] - 1;
        char ny = king[0] + 1;
        char r_nx = rock[1] - 1;
        char r_ny = rock[0] + 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
    else if (c == "LB")
    {
        char nx = king[1] - 1;
        char ny = king[0] - 1;
        char r_nx = rock[1] - 1;
        char r_ny = rock[0] - 1;
        if (valide(nx, ny))
        {
            if (nx == rock[1] && ny == rock[0])
            {
                if (valide(r_nx, r_ny))
                {
                    king[0] = ny;
                    king[1] = nx;
                    rock[0] = r_ny;
                    rock[1] = r_nx;
                }
            }
            else
            {
                king[0] = ny;
                king[1] = nx;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> king >> rock;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        simulation(command);
    }
    cout << king << '\n';
    cout << rock << '\n';
    return 0;
}