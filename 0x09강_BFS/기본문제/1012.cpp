#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int t, n, m, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    // 테스트 케이스만큼 실행하기
    for (int a = 0; a < t; a++)
    {
        // 입력 받아 배열에 삽입하기
        int board[52][52] = {
            0,
        };
        cin >> m >> n >> k;

        for (int b = 0; b < k; b++)
        {
            int x, y;
            cin >> y >> x;
            board[x][y] = -1;
        }

        queue<pair<int, int>> Q;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // 지금 위치가 배추인지(-1) 확인하고 배추이면 큐에 삽입하기
                if (board[i][j] != -1)
                    continue;
                Q.push({i, j});
                ans++;

                while (!Q.empty())
                {
                    // 해당 배추의 위치부터 상하좌우로 확인하며 배추의 위치를 찾고 값 바꾸기(1)
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (board[nx][ny] >= 0)
                            continue;
                        board[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        // 배추흰지렁이의 개수 출력하기
        cout << ans << '\n';
    }
}