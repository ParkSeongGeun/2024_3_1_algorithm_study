#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, cnt, res;
vector<int> v;

int main() {
    cin >> N;
    cin >> M;
    for(int i=0;i<N;i++){
        cin >> cnt;
        v.push_back(cnt);
    }
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    while(left < right) {
        if(v[left] + v[right] == M) {
            res++;
            left++;
            right--;
        } else if(v[left] + v[right] < M) {
            left++;
        } else if(v[left] + v[right] > M) {
            right--;
        }
    }    
    cout << res << "\n";
    return 0;
}