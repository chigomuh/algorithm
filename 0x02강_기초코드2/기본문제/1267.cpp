#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, time, y[20], m[20], sumY = 0, sumM = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> time;
        y[i] = ((time / 30) + 1) * 10;
        m[i] = ((time / 60) + 1) * 15;
    }
    for (int i = 0; i < n; i++)
    {
        sumY += y[i];
        sumM += m[i];
    }
    if (sumY < sumM)
    {
        cout << "Y"
             << " " << sumY;
    }
    else if (sumY > sumM)
    {
        cout << "M"
             << " " << sumM;
    }
    else
    {
        cout << "Y M " << sumY;
    }
}