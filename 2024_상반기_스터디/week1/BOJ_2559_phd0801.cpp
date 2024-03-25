#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, res = -2147483647;
vector<int> v;
int arr[100001];
int cnt[100001];

int main() {
    cin >> N >> M;
    int sum = 0;
    for(int i=0;i<M;i++){
        cin >> cnt[i];
        sum += cnt[i];
    }
    arr[0] = sum;
    for(int i=M;i<=N-1;i++) {
        cin >> cnt[i];
        arr[i-M+1] = arr[i-M] + cnt[i] - cnt[i-M];
    }
    for(int i=0;i<=N-M;i++){
        if(res < arr[i]) {
            res = arr[i];
        }
        //cout << arr[i] << " ";
    }
    //cout << "\n";
    cout << res << "\n";
    return 0;
}