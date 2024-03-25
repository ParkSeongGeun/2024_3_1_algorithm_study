#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int len, flag;
int cnt[26];
vector<string> v;
string s;

int main() {
    cin >> len;
    for(int i=0;i<len;i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<len;i++){
        cnt[v[i][0]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(cnt[i] >= 5){
            cout << char(i + 'a');
            flag++;
        }
    }
    if(flag==0){
        cout << "PREDAJA" << "\n";
    }
    return 0;
}