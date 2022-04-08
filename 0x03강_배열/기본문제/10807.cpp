#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v, t;
    int vArr[101] = {}, vArr_minus[101] = {};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t >= 0)
        {
            vArr[t]++;
        }
        else if (t < 0)
        {
            t = -t;
            vArr_minus[t]++;
        }
    }
    cin >> v;
    if (v >= 0)
    {
        cout << vArr[v];
    }
    else if (v < 0)
    {
        cout << vArr_minus[-v];
    }
}