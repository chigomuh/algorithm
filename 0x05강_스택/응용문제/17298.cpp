#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n;

    int arr[n], ans[n];
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr[i] = k;
    }
    // 배열 2개, 스택으로 계산
    // 스택 내부에는 현재 남은 비교 대상보다 높은 숫자만 있으면 됨
    // 스택 내부에는 밑에서 위로 내림차순으로 존재하면 됨
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        if (st.empty())
        {
            ans[i] = -1;
            st.push(arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}