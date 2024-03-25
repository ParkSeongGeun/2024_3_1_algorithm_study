#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string s;
int N, res;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        stack<char> cnt;
        stack<char> fd;
        cin >> s;
        for(int j=s.length()-1;j>=0;j--){
            cnt.push(s[j]);
        }
        fd.push(cnt.top());
        cnt.pop();
        while(!cnt.empty()) {
            if(fd.empty()){
                fd.push(cnt.top());
                cnt.pop();
            }
            else if(cnt.top() == fd.top()) {
                fd.pop();
                cnt.pop();
            } else if(cnt.top() != fd.top()){
                fd.push(cnt.top());
                cnt.pop();
            }
        }
        if(fd.empty()){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}