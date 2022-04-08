#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, mul = 0;
    cin >> a >> b >> c;

    mul = a * b * c;
    for (int i = 0; i < to_string(mul).length(); i++)
    {
        int idx = to_string(mul)[i] - '0';
        arr[idx] += 1;
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << "\n";
    cout << mul % 10;
}