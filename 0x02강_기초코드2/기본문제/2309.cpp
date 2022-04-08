#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[9], sum = 0;
    bool isBreak = false;

    for (int i = 0; i < 9; i++)
        cin >> arr[i];
    sort(arr, arr + 9);
    for (int i = 0; i < 9; i++)
        sum += arr[i];
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            int sum1 = sum;
            sum1 = sum1 - arr[i] - arr[j];
            if (sum1 == 100)
            {
                isBreak = true;
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << arr[k] << "\n";
                    }
                }
                break;
            }
        }
        if (isBreak == true)
        {
            break;
        }
    }
}