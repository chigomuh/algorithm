#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[20], arr1[20], a, b;

    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
        arr1[i] = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        for (int j = a - 1; j < b; j++)
        {
            arr[j] = arr1[((b - 1) - j + (a - 1))];
        }
        for (int k = 0; k < 20; k++)
        {
            arr1[k] = arr[k];
        }
    }
    for (int i = 0; i < 20; i++)
        cout << arr[i] << " ";
}