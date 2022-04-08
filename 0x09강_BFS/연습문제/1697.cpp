#include <bits/stdc++.h>
using namespace std;

// 수빈이가 이동할 배열 선언
int board[200002];

// 거리를 계산할 배열 선언
int dist[200002];

// 움직일 조건 삽입
int dx[3] = {-1, 1, 2};
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 수빈이의 현재 칸을 제외하고 모든 칸을 갈 수 있으니 -1로 채움
    fill_n(dist, 100002, -1);
    dist[n] = 0;

    queue<int> Q;
    // 큐에 수빈이의 현재 위치를 넣음
    Q.push(n);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        // 조건에 맞게 움직임
        for (int dir = 0; dir < 3; dir++)
        {
            int nx = 0;
            if (dx[dir] == 2)
            {
                nx = cur * dx[dir];
            }
            else
            {
                nx = cur + dx[dir];
            }

            // 음수이거나 배열을 초과하면 continue
            if (nx < 0 || nx > 200002)
                continue;

            // 거리가 입력되었으면 continue
            if (dist[nx] >= 0)
                continue;

            // 현재 방문한 공간의 거리 계산
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }

        // 동생의 위치를 방문하여 거리가 계산되었다면 탈출 후 출력
        if (dist[m] != -1)
        {
            cout << dist[m];
            break;
        }
    }
}