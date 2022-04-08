#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    // h의 범위가 10억이었음,, long long 해야지;; 꼭 기억해라
    long long h, ans = 0;
    cin >> n;

    stack<int> S;

    for (int i = 0; i < n; i++)
    {
        cin >> h;

        while (!S.empty())
        {
            if (S.top() > h)
            {
                ans += S.size();
                S.push(h);
                break;
            }
            else if (S.top() <= h)
            {
                S.pop();
            }
        }

        if (S.empty())
        {
            S.push(h);
        }
    }

    cout << ans;
}