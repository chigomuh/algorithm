#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> lst;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        lst.push_back(s[i]);
    }
    list<char>::iterator t = lst.end();
    int n;
    cin >> n;
    char cmd, s1;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == 'L')
        {
            list<char>::iterator check = lst.begin();
            if (check != t)
                t--;
        }
        else if (cmd == 'D')
        {
            list<char>::iterator check = lst.end();
            if (check != t)
                t++;
        }
        else if (cmd == 'B')
        {
            list<char>::iterator check = lst.begin();
            if (check != t)
            {
                t--;
                t = lst.erase(t);
            }
        }
        else if (cmd == 'P')
        {
            cin >> s1;
            lst.insert(t, s1);
        }
    }
    for (auto ans : lst)
    {
        cout << ans;
    }
}