#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9], max = 0, idx = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
            idx = i + 1;
        }
    }
    cout << max << "\n"
         << idx;
}