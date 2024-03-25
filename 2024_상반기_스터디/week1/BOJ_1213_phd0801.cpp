#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s, res;
char idx;
int arr[26];
int flag;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(char a : s) {
        arr[a-'A']++;
    }
    for(int i=25;i>=0;i--){
        if(arr[i]%2==1){
            flag++; idx = char(i+'A');  
            arr[i]--;
            if(flag==2){
                cout << "I'm Sorry Hansoo" <<"\n";
                return 0;
            }
        }
        for(int j=0;j<arr[i];j+=2){
            res = char(i+'A') + res + char(i + 'A');
        }
    }
    if(flag==1){
        res.insert(res.begin()+res.length()/2, idx);
    } 
    cout << res << "\n";
    return 0;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> s;
//     sort(s.begin(), s.end());
//     do {
//         int flag = 0;
//         for(int i = 0;i<s.length()/2;i++){
//             if(s[i] != s[s.length()-1-i]){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0){
//             for(char a:s) cout << a;
//             cout << "\n";
//             return 0;
//         }
//     }while(next_permutation(s.begin(), s.end()));
//     cout << "I'm Sorry Hansoo" << "\n";
//     return 0;
// }