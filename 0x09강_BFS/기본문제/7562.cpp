#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 나이트가 움직일 배열 생성
int dist[302][302];

// 나이트가 움직일 방향(조건)
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    // 테스트 케이스 만큼 반복
    while (t--)
    {
        cin >> n;

        // -1로 초기화
        for (int i = 0; i < n; i++)
        {
            fill(dist[i], dist[i] + n, -1);
        }

        queue<pair<int, int>> Q;
        int x, y, tx, ty, ans = 0;

        cin >> x >> y;
        cin >> tx >> ty;

        // 시작 위치를 큐에 담고 0으로 지정
        Q.push({x, y});
        dist[x][y] = 0;

        // dfs
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                // 0과 n 사이가 아닌 경우
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                // 방문했는 경우
                if (dist[nx][ny] >= 0)
                    continue;

                // 방문했음을 표시하고 횟수 계산
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                // 도착 위치인 경우 최소 횟수 저장
                if (nx == tx && ny == ty)
                {
                    ans = dist[nx][ny];
                }
                Q.push({nx, ny});
            }
        }

        // 출력
        cout << ans << '\n';
    }
}