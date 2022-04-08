#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[10] = {};

    while (n > 0)
    {
        arr[n % 10]++;
        n /= 10;
    }
    int six_nine = arr[6] + arr[9];
    if (six_nine % 2)
    {
        arr[6] = (six_nine / 2) + 1;
        arr[9] = (six_nine / 2) + 1;
    }
    else
    {
        arr[6] = six_nine / 2;
        arr[9] = six_nine / 2;
    }
    sort(arr, arr + 10);

    cout << arr[9];
}