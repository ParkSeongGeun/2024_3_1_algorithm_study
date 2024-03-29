#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, J, cnt;

int main() {
    cin >> N >> M >> J;
    // 그냥 돌리기만 하면 될듯
    int res = 0;

    int start = 1, ed = M;

    for(int i=0;i<J;i++){
        cin >> cnt;
        while(1) {
            if(start <= cnt && cnt <= ed ) {
                break;
            } else if(start > cnt) {
                start--;
                ed--;
            } else {
                start++;
                ed++;
            }
            res++;
        }
    }

    cout << res << "\n";
    return 0;
}