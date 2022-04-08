#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 집의 위치를 입력 받을 지도(배열)를 선언
string board[27];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // 위치를 입력 받는다.
        cin >> board[i];
    }

    queue<pair<int, int>> Q;
    int ans = 0;
    vector<int> v;

    // 배열을 시작부터 끝까지 돈다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '0')
                continue;

            // 집이 있는 곳( 1 )을 큐에 담고
            Q.push({i, j});

            // 해당 위치를 방문했다는 표시( 0 )를 남긴다.(단지 개수++)
            board[i][j] = '0';
            ans++;

            // 이미 집이 1개 있는 상태
            int cnt = 1;

            // 큐에 담긴 위치에 대한 dfs를 돌린다.
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    // 상하좌우로 돌 때, 0보다 작거나 N 범위를 넘는 경우는 제외한다.
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    // 방문했다면 제외
                    if (board[nx][ny] == '0')
                        continue;

                    // 해당 위치가 집이 있는 위치라면 방문했다는 표시( 0 )를 남기고 큐에 담는다.(집 개수++)
                    board[nx][ny] = '0';
                    Q.push({nx, ny});
                    cnt++;
                }
            }
            v.push_back(cnt);
        }
    }

    // 단지 수와 단지내 집의 수를 출력한다.
    cout << ans << '\n';

    // 오름차순이므로 정렬
    sort(v.begin(), v.end());

    for (auto ans : v)
    {
        cout << ans << '\n';
    }
}