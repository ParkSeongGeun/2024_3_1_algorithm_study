#define ll long long 
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

ll a, b, c, res;

ll makeRes(ll a, ll b, ll c) {
    // 종료 조건
    if(b == 1) {
        return (a % c);
    }
    ll cur = makeRes(a, b/2, c);
    if(b % 2 == 0) {
        res = cur * cur % c;
    } else {
        res = cur * cur % c * a % c;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    makeRes(a, b, c);
    if(b==1) {
        res = a % c;
    }
    cout << res << "\n";
    return 0;
}