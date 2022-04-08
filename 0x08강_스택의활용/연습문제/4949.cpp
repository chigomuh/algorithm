#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        stack<char> st;
        bool ans = true;
        string k;
        getline(cin, k);

        if (k == ".")
            break;

        for (int i = 0; i < k.length(); i++)
        {
            if (k[i] == '(' || k[i] == '[')
            {
                st.push(k[i]);
            }
            else if (k[i] == ')' || k[i] == ']')
            {
                if (st.empty())
                {
                    ans = false;
                    break;
                }
                else if (k[i] == ')')
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        ans = false;
                }
                else if (k[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        ans = false;
                }
            }
        }

        if (!st.empty())
        {
            ans = false;
        }

        if (ans)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}