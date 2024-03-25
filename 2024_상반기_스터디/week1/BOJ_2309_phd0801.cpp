#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int a;

void printV() {
    int sum = 0;
    for(int i=0;i<7;i++) {
        sum += v[i];
    }
    if(sum == 100) {
        for(int i=0;i<7;i++){
            cout << v[i] << "\n";
        }
        exit(0);
    }
    return;
}
void makePermutation(int n, int r, int depth) {
    if(r==depth) {
        printV();
        return;
    }

    for(int i=depth; i<n;i++){
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }

    return;
}

int main() {
    for(int i=0;i<9;i++) {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    makePermutation(9, 7, 0);

    return 0;
}