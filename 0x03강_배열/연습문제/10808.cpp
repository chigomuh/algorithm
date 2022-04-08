#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main(void)
{
    string s;
    int idx = 0;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        idx = static_cast<int>(s[i]) - 97;
        arr[idx] += 1;
    }

    for (int i = 0; i < 26; i++)
        cout << arr[i] << " ";
}