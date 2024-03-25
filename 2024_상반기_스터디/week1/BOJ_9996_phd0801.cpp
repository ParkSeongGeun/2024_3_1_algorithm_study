#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string s, cnt;

vector<string> split(string input, string delimiter) {
    vector<string> ret;

    long long pos = 0;
    string token = "";

    while((pos=input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
int main() {
    cin >> n;
    cin >> s;
    vector<string> a = split(s, "*");
    for(int i=0;i<n;i++){
        int flag = 0;
        long long pos = 0;
        string token = "";
        cin >> cnt;
        if(cnt.length() < a[0].length() + a[1].length()){
            flag = 1;
        }
        if((pos=cnt.find(a[0])) != 0) {
            flag = 1;
        }
        for(int j=0;j<a[1].length();j++){
            if(cnt[cnt.length()-a[1].length()+j] != a[1][j]) {
                flag = 1;
            }
        }
        //cout << "\n";
        //cout << cnt.find(a[0]) << " " << cnt.find(a[1]) << "\n";
        if(flag==1){
            cout << "NE" << "\n";
        } else {
            cout << "DA" << "\n";
        }
    }
    cout << "\n";
    return 0;
}