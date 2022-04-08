#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist[1002][1002];
int dist1[1002][1002];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
        fill(dist1[i], dist1[i] + m, -1);
    }

    queue<pair<int, int>> Q;
    pair<int, int> J;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'J')
            {
                J = {i, j};
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'F')
            {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx >= n || nx < 0 || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    Q.push(J);
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << dist1[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (dist[nx][ny] != -1 && dist[nx][ny] <= dist1[cur.X][cur.Y] + 1)
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}