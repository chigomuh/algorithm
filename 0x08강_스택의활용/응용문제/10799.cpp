#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (!st.empty() && str[i] == ')')
        {
            if (i > 0 && str[i - 1] == '(')
            {
                ans += st.size() - 1;
                st.pop();
            }
            else if (i > 0 && str[i - 1] != '(')
            {
                ans += 1;
                st.pop();
            }
        }
    }
    cout << ans;
}