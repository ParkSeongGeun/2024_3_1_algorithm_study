#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, res, cnt;
vector<pair<int, int> >v;
int MAP[9][9];
int cpy[9][9]; // 원 상태로 되돌리기 위한 map
bool visited[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int y, int x) {
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

            if(MAP[ny][nx]==1||ny<0||nx<0||ny>=N||nx>=M||visited[ny][nx]){
                continue;
            }

            q.push(make_pair(ny, nx));
            MAP[ny][nx] = 2;
            visited[ny][nx] = true;
        }
    }

}
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i=0;i<N;i++ ){
        for(int j=0;j<M;j++){
            cin >> MAP[i][j];
            cpy[i][j] = MAP[i][j];
            if(MAP[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    
    // 3개를 뽑은 다음에
    for(int a=0;a<v.size();a++){
        for(int b=a+1;b<v.size();b++){
            for(int c=b+1;c<v.size();c++){
                MAP[v[a].first][v[a].second] = 1;
                MAP[v[b].first][v[b].second] = 1;
                MAP[v[c].first][v[c].second] = 1;
                cnt = 0;
                // bfs를 돌림 -> 2인 부분에서만 진입
                for(int i=0;i<N;i++ ){
                    for(int j=0;j<M;j++){
                        if(MAP[i][j] == 2 && !visited[i][j]){
                            bfs(i, j);
                        }
                    }
                }

                // bfs를 돈 후에 
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(MAP[i][j] == 0){
                            cnt++;
                        }
                    }
                }
                // cnt를 비교한 후에 map을 다시 원상태로 돌려줌
                res = max(res, cnt);
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        MAP[i][j] = cpy[i][j];
                        visited[i][j] = false;
                    }
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}