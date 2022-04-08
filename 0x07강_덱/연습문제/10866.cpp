#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x)
{
    dat[head--] = x;
}

void push_back(int x)
{
    dat[++tail] = x;
}

int size()
{
    return tail - head;
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

int pop_front()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        head++;
        return dat[head];
    }
}

int pop_back()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return dat[tail--];
    }
}

int front()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return dat[head + 1];
    }
}

int back()
{
    if (empty())
    {
        return -1;
    }
    else
    {
        return dat[tail];
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
        int x;
        if (cmd == "push_front")
        {
            cin >> x;
            push_front(x);
        }
        else if (cmd == "push_back")
        {
            cin >> x;
            push_back(x);
        }
        else if (cmd == "pop_front")
        {
            cout << pop_front() << '\n';
        }
        else if (cmd == "pop_back")
        {
            cout << pop_back() << '\n';
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