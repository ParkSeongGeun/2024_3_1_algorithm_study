#define ll long long 
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

ll cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> cnt) {
        ll comp = 1;
        ll len = 1;
        while(1) {
            ll check = comp % cnt;
            if(check == 0) {
                cout << len << "\n";
                break;
            } else {
                len++;
                comp = comp * 10 + 1;
                comp = (comp % cnt) % cnt;
            }
        }
    }
    return 0;
}