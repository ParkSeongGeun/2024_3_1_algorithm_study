#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main() {
    cin >> s;
    for(int i=0;i<s.length()/2;i++){
        if(s[i] != s[s.length()-1-i]){
            cout << "0" << "\n";
            return 0;
        }
    }
    cout << "1" << "\n";
    return 0;
}