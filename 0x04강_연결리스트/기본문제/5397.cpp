#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        list<char> pwList = {};
        string pw;
        cin >> pw;

        auto t = pwList.begin();

        for (auto cmd : pw)
        {
            if (cmd == '<')
            {
                if (t != pwList.begin())
                {
                    t--;
                }
            }
            else if (cmd == '>')
            {
                if (t != pwList.end())
                {
                    t++;
                }
            }
            else if (cmd == '-')
            {
                if (t != pwList.begin())
                {
                    t--;
                    t = pwList.erase(t);
                }
            }
            else
            {
                pwList.insert(t, cmd);
            }
        }
        for (auto ans : pwList)
        {
            cout << ans;
        }
        cout << '\n';
    }
}