#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> D;
    deque<int> D1;
    for (int i = 1; i < n + 1; i++)
    {
        D.push_back(i);
    }

    int ans = 0;
    while (m--)
    {
        int x;
        cin >> x;
        int D_cnt = 0, D1_cnt = 0, min = 0;
        D1 = D;
        while (D.front() != x)
        {
            D.push_back(D.front());
            D.pop_front();
            D_cnt++;
        }

        while (D1.front() != x)
        {
            D1.push_front(D1.back());
            D1.pop_back();
            D1_cnt++;
        }

        if (D.front() == x)
        {
            D.pop_front();
        }

        min = D_cnt > D1_cnt ? D1_cnt : D_cnt;
        ans += min;
    }

    cout << ans;
}