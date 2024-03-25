#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[26];
string s;

int main() {
    cin >> s;
    for(int i=0;i<s.length();i++){
        arr[s[i] - 'a'] += 1;
    }
    for(int i:arr) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}