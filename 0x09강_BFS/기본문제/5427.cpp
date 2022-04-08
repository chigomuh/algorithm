#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int t, m, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> m >> n;

        // 입력 값을 받은 문자 배열 선언
        string board[1002];

        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
        }

        // 상근이와 불 각각의 시간 배열과 큐 선언
        queue<pair<int, int>> Q_s;
        queue<pair<int, int>> Q_f;
        int dist_s[1002][1002] = {};
        int dist_f[1002][1002] = {};

        // 상근이: ( . ) 인 경우 -1
        // 불: 상근이, ( . ) 인 경우 -1
        // 상근이: 상근이인 경우 담기
        // 불: 불인 경우 담기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                {
                    dist_s[i][j] = -1;
                    dist_f[i][j] = -1;
                }
                else if (board[i][j] == '@')
                {
                    dist_f[i][j] = -1;
                    Q_s.push({i, j});
                }
                else if (board[i][j] == '*')
                {
                    Q_f.push({i, j});
                }
            }
        }

        // 불 dfs
        while (!Q_f.empty())
        {
            pair<int, int> cur = Q_f.front();
            Q_f.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (dist_f[nx][ny] >= 0)
                    continue;

                dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;
                Q_f.push({nx, ny});
            }
        }

        int ans = 0;
        bool isImpos = true;

        // 상근이 dfs
        while (!Q_s.empty() && isImpos)
        {
            pair<int, int> cur = Q_s.front();
            Q_s.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                // 탈출한 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    isImpos = false;
                    ans = dist_s[cur.X][cur.Y] + 1;
                    break;
                }

                // 이미 방문한 경우 or 벽인 경우
                if (dist_s[nx][ny] >= 0)
                    continue;

                dist_s[nx][ny] = dist_s[cur.X][cur.Y] + 1;

                // 불이 못오는 경우 or 상근이가 더 빨리 오는 경우
                if (dist_f[nx][ny] == -1 || dist_s[nx][ny] < dist_f[nx][ny])
                    Q_s.push({nx, ny});
            }
        }

        // 탈출 여부에 따라 출력
        if (isImpos)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
        else
        {
            cout << ans << '\n';
        }
    }
}