#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        string a, b;
        cin >> a >> b;
        string aArr[1000], bArr[1000];
        for (int i = 0; i < a.length(); i++)
        {
            aArr[i] = a[i];
        }
        for (int i = 0; i < b.length(); i++)
        {
            bArr[i] = b[i];
        }
        sort(aArr, aArr + a.length());
        sort(bArr, bArr + b.length());

        string c = "", d = "";
        for (int i = 0; i < a.length(); i++)
        {
            c += aArr[i];
        }
        for (int i = 0; i < b.length(); i++)
        {
            d += bArr[i];
        }
        if (c == d)
        {
            cout << "Possible" << '\n';
        }
        else
        {
            cout << "Impossible" << '\n';
        }
    }
}