#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    // 쌍을 가진 Stack 생성
    stack<pair<int, int>> S;

    // n만큼 돈다
    for (int i = 1; i < n + 1; i++)
    {
        cin >> k;

        // 스택이 비어있지 않다면 --> top을 꺼낼 수 있다면
        while (!S.empty())
        {
            // 입력된 높이가 스택 탑의 높이 보다 크다면
            // 현재 스택의 탑은 필요가 없기에 삭제
            if (k > S.top().second)
            {
                S.pop();
            }
            // 입력된 높이가 현재 탑보다 작다면
            // 현재 탑의 인덱스를 출력하고 스택에 삽임
            else
            {
                cout << S.top().first << " ";
                S.push(make_pair(i, k));
                break;
            }
        }

        // 스택이 비어있다면
        if (S.empty())
        {
            // 현재 입력된 값을 스택에 삽입 후 0 출력
            S.push(make_pair(i, k));
            cout << 0 << " ";
        }
    }
}