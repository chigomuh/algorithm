#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n;

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while (!st.empty() && st.top().first < k)
        {
            ans += st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first > k)
        {
            ans += st.top().second;
        }
        else if (!st.empty() && st.top().first == k)
        {
            ans += st.top().second;
            st.top().second++;
        }
        else
        {

            st.push(make_pair(k, 1));
        }
    }
}