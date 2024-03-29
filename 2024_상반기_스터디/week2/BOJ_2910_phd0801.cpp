#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, C;
// m1 -> 몇 번 입력되었는지
// m2 -> 어떤 인덱스에서 입력되었는지
map<int, int> m1, m2;
vector<pair<int, int> > v; 

bool compare(pair<int, int> i, pair<int, int> j) {
    if(i.first == j.first) {
        return m2[i.second] < m2[j.second];
    }
    return i.first > j.first;
}

int main() {
    cin >> N >> C;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        m1[a]++;
        if(m2[a] == 0) {
            m2[a] = i + 1;
        }
    }

    for(auto it : m1) {
        v.push_back(make_pair(it.second, it.first));
    }

    sort(v.begin(), v.end(), compare);
    
    for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	} 
    return 0;

}