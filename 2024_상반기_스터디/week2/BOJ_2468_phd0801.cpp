#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

bool visited[101][101];
int map[101][101];
int cpy[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N, res = -2147483647, cnt, cur = -2147483647;

void bfs(int y, int x) {
    if(visited[y][x]||x<0||y<0||x>=N||y>=N) {
        return ;
    }

    visited[y][x] = true;

    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(map[ny][nx] < 1||visited[ny][nx]||nx<0||ny<0||nx>=N||ny>=N) {
                continue;
            }
            q.push(make_pair(ny, nx));
            visited[ny][nx] = true;
        }
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            cin >> cpy[i][j];
            cur = max(cur, cpy[i][j]);
        }
    }

    for(int k=0;k<cur;k++){
        cnt = 0;
        for(int i= 0;i<N;i++){
            for(int j=0;j<N;j++){
                map[i][j] = cpy[i][j] - k;
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]&&map[i][j]>=1){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        res = max(res, cnt);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                visited[i][j] = false;
            }
        }
    }
    cout << res << "\n";
    return 0;
}