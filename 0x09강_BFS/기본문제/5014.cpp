#include <bits/stdc++.h>
using namespace std;

int board[1000002];
int f, s, g, u, d;
int dx[2];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    // F층만큼 -1로 채우기
    fill(board + 1, board + f + 1, -1);

    // U, D 조건 배열에 담기
    dx[0] = u;
    dx[1] = d * -1;

    queue<int> Q;

    // 강호의 위치를 큐에 담고 계산을 위해 0값 주기
    Q.push(s);
    board[s] = 0;

    // dfs
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 2; dir++)
        {
            int nx = cur + dx[dir];

            // 조건을 맞추어 돌 때, 범위를 벗어나면 엘리베이터는 움직이지 않음
            if (nx < 1 || nx >= f + 1)
                continue;

            // 방문한 경우 pass
            if (board[nx] >= 0)
                continue;

            // 처음 방문했다면 거리++
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }
    }

    // 만약 스타트링크를 방문하지 않았다면
    if (board[g] == -1)
    {
        cout << "use the stairs";
    }
    else
    {
        // 방문했다면 스타트링크를 방문하기 위해 누른 횟수 출력
        cout << board[g];
    }
}