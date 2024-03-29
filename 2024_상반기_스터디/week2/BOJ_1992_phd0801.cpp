#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[65][65];

void go(int size, int y, int x)
{
    if(size == 1)
    {
        cout << arr[y][x];
        return ;
    }
    int check_one = 0;
    int check_zero = 0;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(arr[i][j] == 1)
                check_one = 1;
            if(arr[i][j] == 0)
                check_zero = 1;
        }
    }
    if (check_one == 0){
        cout << 0;
        return;
    }
    if (check_zero == 0){
        cout << 1;
        return ;
    }
    cout << "(";
    go(size/2, y, x);
    go(size/2, y, x + size/2);
    go(size/2, y+size/2, x);
    go(size/2, y+size/2, x+size/2);
    cout << ")";
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++){
            arr[i][j] = s[j]-'0';
        }
    }

    go(N, 0, 0);
}