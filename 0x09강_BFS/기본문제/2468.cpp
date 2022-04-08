#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 배열, 조건 선언
int board[102][102];
int dist[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int mx = 0, mn = 102;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 높이를 입력받고 최대, 최소값 확인
            cin >> board[i][j];
            if (board[i][j] > mx)
                mx = board[i][j];
            if (board[i][j] < mn)
                mn = board[i][j];
        }
    }

    int ans = 1;
    vector<int> v;

    // 높이 최소값 ~ 최대값-1 까지 확인
    for (int k = mn; k < mx; k++)
    {
        int cnt = 0;

        // 현재 잠긴 위치 확인
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] <= k)
                    dist[i][j] = 0;
                else
                    dist[i][j] = -1;
            }
        }

        queue<pair<int, int>> Q;

        // 비가 온 높이로 갱신된 배열에 대한 dfs
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] >= 0)
                    continue;
                Q.push({i, j});

                // 안전한 영역 개수++
                cnt++;

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
                        if (dist[nx][ny] >= 0)
                            continue;

                        dist[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        v.push_back(cnt);
    }

    // 개수 확인 후 최대값 출력
    for (auto cnt : v)
    {
        if (ans < cnt)
            ans = cnt;
    }

    cout << ans;
}