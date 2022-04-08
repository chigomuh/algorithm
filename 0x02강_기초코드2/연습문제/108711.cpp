#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, arr[10000];
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (x > arr[i])
        {
            cout << arr[i] << " ";
        }
    }
}