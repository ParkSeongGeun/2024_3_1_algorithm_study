#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c;
int res;
int start, ed;
int arr[101];

int main() {
    cin >> a >> b >> c;
    for(int i=0;i<3;i++){
        cin >> start >> ed;
        for(int j=start;j<ed;j++){
            arr[j]++;
        }
    }
    for(int i=1;i<=100;i++){
        if(arr[i]==1){
            res += a;
        } else if(arr[i]==2){
            res += b * 2;
        } else if(arr[i]==3){
            res += c * 3;
        }
    }
    cout << res << "\n";
    return 0;
}