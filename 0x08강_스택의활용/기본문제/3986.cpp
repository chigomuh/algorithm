#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    while (n--)
    {
        string str;
        cin >> str;
        stack<char> st;

        for (int i = 0; i < str.length(); i++)
        {
            if (st.empty())
                st.push(str[i]);
            else if (str[i] == 'A')
            {
                if (st.top() == 'A')
                    st.pop();
                else
                    st.push(str[i]);
            }
            else if (str[i] == 'B')
            {
                if (st.top() == 'B')
                    st.pop();
                else
                    st.push(str[i]);
            }
        }

        if (st.empty())
            ans++;
    }

    cout << ans;
}