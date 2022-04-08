#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos++] = x;
}

int pop()
{
    if (pos != 0)
    {
        pos--;
        return dat[pos];
    }
    else
    {
        return -1;
    }
}

int size()
{
    return pos;
}

int empty()
{
    if (pos == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top()
{
    if (pos != 0)
    {
        return dat[pos - 1];
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string cmd;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> x;
            push(x);
        }
        else if (cmd == "pop")
        {
            cout << pop() << '\n';
        }
        else if (cmd == "size")
        {
            cout << size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << empty() << '\n';
        }
        else if (cmd == "top")
        {
            cout << top() << '\n';
        }
    }
}