#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string s;
int N, M;
int arr[101][101];
bool visited[101][101];
int dist[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    dist[x][y] = 1;
    visited[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > N || ny <= 0 || ny > M || visited[nx][ny] || arr[nx][ny] == 0) continue;

            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
            visited[nx][ny] = true;
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> s;
        for(int j=1;j<=s.length();j++){
            arr[i][j] = s[j-1] - '0';
        }
    }
    bfs(1, 1);
    
    cout << dist[N][M] << "\n";
    return 0;
}