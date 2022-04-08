#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    string cmd, str = "", s = "";
    while (t--)
    {
        bool isR = false;
        bool err = false;

        deque<int> D;
        cin >> cmd >> n >> str;

        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] != ',' && str[i] != ']')
            {
                s += str[i];
            }
            else
            {
                D.push_back(atoi(s.c_str()));
                s = "";
            }
        }

        for (int i = 0; i < cmd.length(); i++)
        {
            if (cmd[i] == 'R')
            {
                if (isR)
                {
                    isR = false;
                }
                else
                {
                    isR = true;
                }
            }
            else if (cmd[i] == 'D')
            {
                if (D.empty() || n == 0)
                {
                    err = true;
                    break;
                }
                if (isR)
                {
                    D.pop_back();
                }
                else
                {
                    D.pop_front();
                }
            }
        }

        if (err)
        {
            cout << "error" << '\n';
        }
        else if (n == 0)
        {
            cout << "[]\n";
        }
        else if (isR)
        {
            cout << "[";
            while (!D.empty())
            {
                cout << D.back();
                D.pop_back();
                if (!D.empty())
                {
                    cout << ',';
                }
            }
            cout << "]" << '\n';
        }
        else
        {
            cout << '[';
            while (!D.empty())
            {
                cout << D.front();
                D.pop_front();
                if (!D.empty())
                {
                    cout << ',';
                }
            }
            cout << "]" << '\n';
        }
    }
}