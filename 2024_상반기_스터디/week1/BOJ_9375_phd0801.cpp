#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, cnt, res;
string a, b;

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        vector<pair<int, string> > v;
        res = 1;

        cin >> cnt;
        for(int j=0;j<cnt;j++){
            int flag = 0;
            cin >> a >> b;
            for(int k=0;k<v.size();k++){
                if(v[k].second == b) {
                    flag = 1;
                    v[k].first++;
                }
            }
            if(flag==0){
                v.push_back(make_pair(1, b));
            }
        }
        for(int j=0;j<v.size();j++){
            res *= (v[j].first + 1);
        }
        res--;
        cout << res << "\n";
    }
    return 0;
}