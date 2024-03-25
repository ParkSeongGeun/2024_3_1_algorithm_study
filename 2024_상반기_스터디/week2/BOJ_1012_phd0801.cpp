#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>


using namespace std;

int N, M, K, cnt, res;
int arr[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x,int y)  {
    if(arr[x][y]!=1||visited[x][y]||x<0||y<0||x>=M||y>=N) {
        return ;
    }

    visited[x][y] = true;
    res++;
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny]!=1||visited[nx][ny]||nx<0||ny<0||nx>=M||ny>=N) {
                continue;
            }

            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> cnt;
    for(int i=0;i<cnt;i++ ){
        res = 0;
        cin >> M >> N >> K;
        for(int i=0;i<K;i++){
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[j][i]&&arr[j][i]==1) {
                    bfs(j, i);
                }
            }
        }
        cout << res << "\n";
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                visited[i][j] = false;
                arr[i][j] = 0;
            }
        }
    }
    return 0;
}