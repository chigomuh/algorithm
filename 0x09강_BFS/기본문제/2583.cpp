#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, k;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    // M * N 크기의 배열을 만들고 -1로 채운다.
    for (int i = 0; i < n; i++)
    {
        fill(board[i], board[i] + m, -1);
    }

    // K개 만큼 입력 받으며 입력 받은 시작좌표에서 종료좌표까지 배열을 0으로 채운다.
    while (k--)
    {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int i = sx; i < ex; i++)
        {
            for (int j = sy; j < ey; j++)
            {
                board[i][j] = 0;
            }
        }
    }

    int ans = 0;
    queue<int> Q_ANS;
    // vector<int> V;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] >= 0)
                continue;

            // 직사각형이 없는 부분(-1)을 큐에 넣는다.
            queue<pair<int, int>> Q;
            Q.push({i, j});

            // 해당 위치 값을 1로 채운다.
            board[i][j] = 1;

            // 빈 공간의 개수를 1 증가
            ans++;

            int cnt = 1;

            // 큐에 담긴 위치에 대한 dfs
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx >= n || nx < 0 || ny >= m || ny < 0)
                        continue;
                    if (board[nx][ny] >= 0)
                        continue;

                    board[nx][ny] = 1;
                    Q.push({nx, ny});

                    // 해당 영역에 대한 넓이를 1 증가
                    cnt++;
                }
            }
            Q_ANS.push(cnt);
            // V.push_back(cnt);
        }
    }

    // 큐에 담긴 값을 넓이를 담을 배열에 옮기고 정렬 후 출력한다.
    int arr[ans] = {};

    cout << ans << '\n';

    for (int i = 0; i < ans; i++)
    {
        arr[i] = Q_ANS.front();
        Q_ANS.pop();
    }

    sort(arr, arr + ans);

    for (int i = 0; i < ans; i++)
    {
        cout << arr[i] << " ";
    }

    // sort(V.begin(), V.end());
    // for (auto ans : V)
    // {
    //     cout << ans << " ";
    // }
}