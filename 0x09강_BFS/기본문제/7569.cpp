#include <bits/stdc++.h>
using namespace std;

// 3차원 배열 선언(토마토 상자와 거리를 담을 배열)
int board[102][102][102];
int dist[102][102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dz[2] = {1, -1};
int n, m, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    queue<tuple<int, int, int>> Q;

    // 거리 배열을 -1로 채운다.
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
            fill(dist[i][j], dist[i][j] + m, -1);
    }

    // 입력 값을 채운다.
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[i][j][k];

                // 거리 배열에 토마토가 없다면 0, 토마토가 있다면 0과 큐에 담는다.(익은 토마토를 기준으로 확인하기 위해서)
                if (board[i][j][k] == -1)
                    dist[i][j][k] = 0;
                else if (board[i][j][k] == 1)
                {
                    Q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nx, ny, nz;
            if (dir < 4)
            {
                nx = get<1>(cur) + dx[dir];
                ny = get<2>(cur) + dy[dir];
                nz = get<0>(cur);
            }
            else if (dir < 6)
            {
                nx = get<1>(cur);
                ny = get<2>(cur);
                nz = get<0>(cur) + dz[dir - 4];
            }

            // x, y, z가 각각 n, m, h와 같거나 크지 않고 0보다 작지 않아야 한다.
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz >= h || nz < 0)
                continue;
            // 해당 위치의 거리가 -1이어야 한다.(초기값; 방문하지 않음)
            if (dist[nz][nx][ny] >= 0)
                continue;
            // 해당 위치의 거리를 기준이 되는 위치(현재 익은 토마토)의 거리 + 1로 지정한다.
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

            // 해당 위치를 큐에 담는다.
            Q.push({nz, nx, ny});
        }
    }

    int mx = 0;
    bool isPos = true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                // 값이 -1(방문하지 않은)인 경우
                if (dist[i][j][k] == -1)
                {
                    isPos = false;
                    break;
                }
                // 거리 값이 가장 큰 값을 최소일 수로 지정한다.
                else if (dist[i][j][k] > mx)
                    mx = dist[i][j][k];
            }
        }
    }

    if (isPos)
        cout << mx;
    else
        cout << -1;
}