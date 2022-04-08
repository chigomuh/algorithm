#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr1[26] = {}, arr2[26] = {};
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        arr1[s1[i] - 97]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        arr2[s2[i] - 97]++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i])
        {
            if (arr1[i] > arr2[i])
            {
                ans += arr1[i] - arr2[i];
            }
            else if (arr1[i] < arr2[i])
            {
                ans += arr2[i] - arr1[i];
            }
        }
    }
    cout << ans;
}