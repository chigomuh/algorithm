#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
int dist[102][102];
int dist1[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 배열에 문자열을 담는다.
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    // 방문여부를 체크하는 배열을 만든다.
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + n, -1);
        fill(dist1[i], dist1[i] + n, -1);
    }

    queue<pair<int, int>> Q;
    int ans1 = 0, ans2 = 0;

    // 문자열을 담은 배열을 처음부터 마지막까지 돈다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 방문하지 않은 문자를 확인한다.
            if (dist[i][j] >= 0)
                continue;

            // 방문하지 않은 문자를 큐에 넣는다.
            Q.push({i, j});
            dist[i][j] = 0;

            // 조건(상하좌우)에 맞춰 bfs를 수행한다.
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    // 해당 문자와 조건에 맞는 문자가 다르다면 넘어간다.
                    if (dist[nx][ny] >= 0 || board[nx][ny] != board[cur.X][cur.Y])
                        continue;

                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
            }
            // bfs가 끝나면 구역의 수를 증가 시킨다.
            ans1++;
        }

        for (int k = 0; k < n; k++)
        {
            if (dist1[i][k] >= 0)
                continue;
            Q.push({i, k});
            dist1[i][k] = 0;

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (dist1[nx][ny] >= 0)
                        continue;

                    // 조건 부분에 R과 G를 같다고 판단하여 수행한다.
                    if (board[cur.X][cur.Y] == 'R' || board[cur.X][cur.Y] == 'G')
                    {
                        if (board[nx][ny] == 'B')
                            continue;
                    }
                    else if (board[cur.X][cur.Y] != board[nx][ny])
                    {
                        continue;
                    }
                    dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
            }
            ans2++;
        }
    }
    cout << ans1 << " " << ans2;
}