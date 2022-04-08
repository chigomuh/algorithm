#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    bool isPos = true;
    int tmp = 1;
    int ans = 0;

    for (int i = 0; i < str.length(); i++)
    {
        // 스택이 비어있는 경우
        if (st.empty())
        {
            if (str[i] == ')' || str[i] == ']')
            {
                isPos = false;
                break;
            }
        }

        // 여는 괄호가 나올 경우
        if (str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
            if (str[i] == '(')
                tmp *= 2;
            else
                tmp *= 3;
        }

        // 닫는 괄호가 나올 경우
        else if (str[i] == ')')
        {
            if (st.top() != '(')
            {
                isPos = false;
                break;
            }
            else if (i > 0 && str[i - 1] == '(')
                ans += tmp;
            tmp /= 2;
            st.pop();
        }
        else if (str[i] == ']')
        {
            if (st.top() != '[')
            {
                isPos = false;
                break;
            }
            else if (i > 0 && str[i - 1] == '[')
                ans += tmp;
            tmp /= 3;
            st.pop();
        }
    }

    // 반복문 수행 후 스택이 비어있지 않는 경우
    if (!st.empty())
        isPos = false;

    // 출력 부분
    if (isPos)
        cout << ans;
    else
        cout << 0;
}