#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
int map[104][104];
bool visited[104][104];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int cnt, res;
vector<int> v;

void bfs(int y, int x) {
    visited[y][x] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));

    res++;
    cnt = 1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0||nx<0||ny>=N||nx>=M||visited[ny][nx]==true){
                continue;
            }
            if(map[ny][nx]==0){
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }
    v.push_back(cnt);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<K;i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        for(int j=y1;j<y2;j++){
            for(int k=x1;k<x2;k++){
                map[j][k] = 1;
            }
        }
    }

    for(int j=0;j<N;j++){
        for(int k=0;k<M;k++){
            if(!visited[j][k]&&map[j][k]==0){
                bfs(j,k);
            }
        }
    }
    cout << res << "\n";
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
}