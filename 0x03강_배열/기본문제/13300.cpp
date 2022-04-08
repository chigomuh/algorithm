#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mArr[6] = {}, fArr[6] = {};
    int n, k, s, y;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> y;
        if (s == 0)
        {
            fArr[y - 1]++;
        }
        else if (s == 1)
        {
            mArr[y - 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        ans += ((mArr[i] + (k - 1)) / k) + ((fArr[i] + (k - 1)) / k);
    }
    cout << ans;
}