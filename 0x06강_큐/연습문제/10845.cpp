#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
    dat[tail++] = x;
}

int size()
{
    return tail - head;
}

int pop()
{
    if (size() == 0)
    {
        return -1;
    }
    else
    {
        return dat[head++];
    }
}

int front()
{
    if (size() == 0)
    {
        return -1;
    }
    else
    {
        return dat[head];
    }
}

int back()
{
    if (size() == 0)
    {
        return -1;
    }
    else
    {
        return dat[tail - 1];
    }
}

int empty()
{
    if (size() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string cmd;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int k;
            cin >> k;
            push(k);
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
        else if (cmd == "front")
        {
            cout << front() << '\n';
        }
        else if (cmd == "back")
        {
            cout << back() << '\n';
        }
    }
}