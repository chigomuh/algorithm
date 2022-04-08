#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> lst;
    for (int i = 1; i < n + 1; i++)
    {
        lst.push_back(i);
    }

    auto t = lst.begin();
    cout << '<';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            lst.push_back(*lst.begin());
            lst.pop_front();
        }
        if (i == n - 1)
        {
            cout << *lst.begin();
        }
        else
        {
            cout << *lst.begin() << ", ";
        }
        lst.pop_front();
    }
    cout << '>';
}