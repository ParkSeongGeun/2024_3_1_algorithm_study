#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

string s;

int main() {
    getline(cin, s);
    for(int i=0;i<s.length();i++){
        if('a'<=s[i]&&s[i]<='z'){
            if(s[i]+13 > 'z'){
                s[i] -= 13;
            } else {
                s[i] += 13;
            }
        }
        else if('A'<=s[i]&&'Z'>=s[i]) {
            if(s[i]+13 > 'Z'){
                s[i] -= 13;
            } else {
                s[i] += 13;
            }
        }
    }
    cout << s << "\n";
    return 0;
}