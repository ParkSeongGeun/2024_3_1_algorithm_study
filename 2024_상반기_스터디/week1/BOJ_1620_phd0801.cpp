#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string arr[100001];
map<string, int> m;
string s, cnt;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> cnt;
        arr[i] = cnt;
        m.insert(make_pair(cnt, i)); 
    }

    for(int i=0;i<M;i++){
        cin >> s;
        if(s[0]>='0'&&s[0]<='9'){
            int num = stoi(s);
            cout << arr[num-1] << "\n";
        } else {
            cout << m[s] + 1 << "\n";
        }
    }
    return 0;
}