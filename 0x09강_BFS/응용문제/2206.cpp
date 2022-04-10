#include <bits/stdc++.h>
using namespace std;
#define X get<0>
#define Y get<1>
#define B get<2>

// 입력값을 받을 배열
string board[1002];

// 거리를 계산할 배열(벽을 부수지 않은 차원, 벽을 부순 차원)
int dist[1002][1002][2];

//움직일 조건
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 입력값을 채움
    for (int i = 0; i < n; i++)
        cin >> board[i];

    // 각각의 차원을 -1로 채움(아직 방문하지 않음)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    // 문제에서 1, 1의 위치에서 시작한다고 제시됨
    // 시작하는 칸을 포함하여 경로를 계산함
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});

    // 출력을 위한 변수
    bool isPos = false;

    // bfs
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();

        // N, M의 위치에 방문했을 경우
        if (X(cur) == (n - 1) && Y(cur) == (m - 1))
        {
            cout << dist[X(cur)][Y(cur)][B(cur)];
            isPos = true;
            break;
        }
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];
            int br = B(cur);

            // 범위를 벗어난 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 벽이 아니고 현재 차원에서 방문할 수 있는 경우
            if (board[nx][ny] == '0' && dist[nx][ny][br] == -1)
            {
                // 현재 차원의 배열의 값을 + 1
                dist[nx][ny][br] = dist[X(cur)][Y(cur)][br] + 1;
                Q.push({nx, ny, br});
            }

            // 현재, 벽이고 벽을 부수지 않은 차원이면서 벽을 부쉈을 때 방문할 수 있는 경우(해당 벽을 처음 부수는 경우)
            if (board[nx][ny] == '1' && br == 0 && dist[nx][ny][1] == -1)
            {
                // 벽을 부순 차원의 값을 현재 차원의 값 + 1
                dist[nx][ny][1] = dist[X(cur)][Y(cur)][br] + 1;

                // 벽을 부쉈으므로 벽을 부순 차원으로 push
                Q.push({nx, ny, 1});
            }
        }
    }

    // 만약 끝나는 칸에 도착하지 못한 경우
    if (isPos == false)
    {
        cout << -1;
    }
}