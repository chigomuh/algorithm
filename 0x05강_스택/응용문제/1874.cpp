#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int dat[N];
int pos = 0, idx = 0;
bool isPos = true;
string cmd = "";

void push(int x)
{
    dat[pos++] = x;
    if (x != -1)
    {
        cmd += '+';
    }
}

void pop()
{
    pos--;
    dat[pos] = -1;
    cmd += "-";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (isPos == false)
        {
            continue;
        }

        if (pos < x)
        {
            while (pos < x)
            {
                if (dat[pos] != -1)
                {
                    push(pos + 1);
                }
                else
                {
                    push(-1);
                }
            }
            pop();
        }
        else if (pos == x)
        {
            pop();
        }
        else if (pos > x)
        {
            int chk = 0;
            while (--pos)
            {
                if (dat[pos] != -1)
                {
                    chk = dat[pos];
                    break;
                }
            }
            if (chk != x)
            {
                isPos = false;
            }
            else
            {
                pos++;
                pop();
            }
        }
    }

    if (isPos == true)
    {
        for (auto ans : cmd)
        {
            cout << ans << '\n';
        }
    }
    else
    {
        cout << "NO";
    }
}