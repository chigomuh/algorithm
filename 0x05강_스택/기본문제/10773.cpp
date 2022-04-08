#include <bits/stdc++.h>
using namespace std;

const int K = 100001;
int dat[K];
int pos = 0;

void push(int x)
{
    dat[pos++] = x;
}

void pop()
{
    pos--;
    dat[pos] = 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;
        if (x == 0)
        {
            pop();
        }
        else
        {
            push(x);
        }
    }
    int ans = 0;
    for (auto x : dat)
    {
        if (x != 0)
        {
            ans += x;
        }
        else
        {
            break;
        }
    }
    cout << ans;
}