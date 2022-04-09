#include <bits/stdc++.h>
using namespace std;
#define Z get<0>
#define X get<1>
#define Y get<2>

// 입력값을 받을 배열 선언
string board[32][32];

// 움직일 조건 선언
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int dz[2] = {1, -1};
int l, r, c;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 테스트 케이스를 입력 받음
    while (true)
    {
        cin >> l >> r >> c;

        // 탈출 조건
        if (l == 0 && r == 0 && c == 0)
            break;

        // 입력값을 받아서 채움
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> board[i][j];
            }
        }

        // 테스트 케이스마다 거리 배열을 초기화
        int dist[32][32][32] = {};
        queue<tuple<int, int, int>> Q;
        tuple<int, int, int> E;

        // 입력된 값을 체크하면서 거리 배열을 채움
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    if (board[i][j][k] == 'S')
                    {
                        // 현재 위치를 담음
                        Q.push({i, j, k});
                    }
                    else if (board[i][j][k] == '.' || board[i][j][k] == 'E')
                    {
                        dist[i][j][k] = -1;
                        if (board[i][j][k] == 'E')
                        {
                            E = {i, j, k};
                        }
                    }
                }
            }
        }

        // 현재 위치에 대한 dfs
        while (!Q.empty())
        {
            tuple<int, int, int> cur = Q.front();
            Q.pop();

            // 조건에 맞게 확인
            for (int dir = 0; dir < 6; dir++)
            {
                int nx, ny, nz;
                if (dir < 4)
                {
                    nx = X(cur) + dx[dir];
                    ny = Y(cur) + dy[dir];
                    nz = Z(cur);
                }
                else
                {
                    nx = X(cur);
                    ny = Y(cur);
                    nz = Z(cur) + dz[dir - 4];
                }

                // 범위를 벗어난 경우
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
                    continue;

                // 방문했거나 방문하지 못할 경우
                if (dist[nz][nx][ny] >= 0)
                    continue;

                // 해당 거리 계산
                dist[nz][nx][ny] = dist[Z(cur)][X(cur)][Y(cur)] + 1;

                // 방문한 위치에 대한 dfs를 수행하기 위해 push
                Q.push({nz, nx, ny});
            }
        }

        // 탈출하지 못한 경우
        if (dist[Z(E)][X(E)][Y(E)] == -1)
        {
            cout << "Trapped!" << '\n';
        }

        // 탈출한 경우
        else
        {
            cout << "Escaped in " << dist[Z(E)][X(E)][Y(E)] << " minute(s).\n";
        }
    }
}