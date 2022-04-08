#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, sum, min;
    sum = 0;
    min = 100;

    for (int i = 0; i < 7; i++)
    {
        cin >> a;
        if (a % 2 == 1)
        {
            sum += a;
            if (min > a)
            {
                min = a;
            }
        }
    }
    if (min == 100)
    {
        cout << -1;
    }
    else
    {
        cout << sum << "\n"
             << min;
    }
}