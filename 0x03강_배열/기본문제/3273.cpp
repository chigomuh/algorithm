#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, cnt = 0;

    cin >> n;
    int n_arr[n + 1] = {};
    for (int i = 0; i < n; i++)
        cin >> n_arr[i];
    cin >> x;

    int x_arr[x + 1] = {};
    for (int i = 0; i < n; i++)
    {
        if ((x - n_arr[i]) > 0)
        {
            if (x_arr[(x - n_arr[i])])
            {
                cnt++;
            }
            x_arr[n_arr[i]]++;
        }
    }
    cout << cnt;
}