#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        stack<char> st;
        bool isVPS = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (st.empty() || str[i] == '(')
                st.push(str[i]);
            else if (str[i] == ')')
            {
                if (st.empty() || st.top() == ')')
                    isVPS = false;
                else if (st.top() == '(')
                    st.pop();
            }
        }
        if (!st.empty())
            isVPS = false;

        if (isVPS)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}