#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];
vector<int> v;
int N, M;

void printV() {
    for(int i=0;i<M;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    return ;
}

void combi(int start) {
    if (v.size() == M) {
        printV();
        return;
    }
    for(int i = start + 1; i <= N; i++) {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
    return ;
}

int main() {
    cin >> N >> M;
    // for(int i=1;i<=N;i++){
    //     a[i] = i;
    // }
    combi(0);
    return 0;
}

// vector<string> split(string input, string delimiter) {
//     vector<string> ret;
//     long long pos = 0;
//     string token = "";
//     while((pos = input.find(delimiter)) != string::npos) {
//         token = input.substr(0, pos);
//         ret.push_back(token);
//         input.erase(0, pos + delimiter.length());
//     }
//     ret.push_back(token);
//     return ret;
// }
// vector<int> v;
// int n, m;

// void printV(vector<int> v) {
//     for(int i :v) cout << i << " ";
//     cout << "\n";
//     return ;
// }

// void makePermutation(int n, int r, int depth) {
//     cout << n << " : " << r << " : " << depth << "\n";
//     if(r==depth) {
//         printV(v);
//         return ;
//     }
//     for(int i = depth; i<n;i++){
//         swap(v[i], v[depth]);
//         makePermutation(n, r, depth + 1);
//         swap(v[i], v[depth]);
//     }
//     return;
// }

// int main() {
//     cin >> n;
//     for(int i = 0; i<n;i++){
//         cin >> m;
//         v.push_back(m); 
//     }
//     sort(v.begin(), v.end());
//     makePermutation(n, n, 0);
//     // do {
//     //     for(int i: v) cout << i << " ";
//     //     cout << "\n";
//     // }while(next_permutation(v.begin(), v.end()));
//     return 0;
// }